//
// Copyleft  F.Chaxel 2017
//

#include "config.h"
#include "txbuf.h"
#include "client.h"

#include "handlers.h"
#include "datalink.h"
#include "dcc.h"
#include "tsm.h"
// conflict filename address.h with another file in default include paths
#include "./include/address.h"
#include "bip.h"

#include "device.h"
#include "ai.h"
#include "bo.h"

#include "esp_system.h"
#include "esp_wifi.h"
#include "esp_event_loop.h"
#include "esp_log.h"
#include "nvs_flash.h"

#include "lwip/err.h"
#include "lwip/sys.h"

#include "driver/gpio.h"

#include "lwip/sockets.h"
#include "lwip/netdb.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"

// hidden function not in any .h files
extern uint8_t temprature_sens_read();
extern uint32_t hall_sens_read();
/* flag for signalling errors */
static bool Error_Detected = false;
void Send_I_Am2(
    uint8_t * buffer);
	int iam_encode_apdu(
    uint8_t * apdu,
    uint32_t device_id,
    unsigned max_apdu,
    int segmentation,
    uint16_t vendor_id);
extern int iam_encode_pdu(
    uint8_t * buffer,
    BACNET_ADDRESS * dest,
    BACNET_NPDU_DATA * npdu_data);
 void MyAbortHandler(
    BACNET_ADDRESS * src,
    uint8_t invoke_id,
    uint8_t abort_reason,
    bool server);

 void MyRejectHandler(
    BACNET_ADDRESS * src,
    uint8_t invoke_id,
    uint8_t reject_reason);
	//add your wıfı settıngs here
// Wifi params
wifi_config_t wifi_config = {
    .sta = {
        .ssid = "blackbox",
        .password = "argentum",
    },
};

// GPIO 5 has a Led on Sparkfun ESP32 board
#define BACNET_LED 17

 //uint8_t Handler_Transmit_Buffer[MAX_PDU]={0} ;
uint8_t Rx_Buf[MAX_MPDU] = { 0 };

EventGroupHandle_t wifi_event_group;
const static int CONNECTED_BIT = BIT0;

void MyAbortHandler(
    BACNET_ADDRESS * src,
    uint8_t invoke_id,
    uint8_t abort_reason,
    bool server)
{
    (void) src;
    (void) invoke_id;
    (void) server;
   // printf("BACnet Abort: %s\n", bactext_abort_reason_name(abort_reason));
    Error_Detected = true;
}


void MyRejectHandler(
    BACNET_ADDRESS * src,
    uint8_t invoke_id,
    uint8_t reject_reason)
{
    (void) src;
    (void) invoke_id;
    //printf("BACnet Reject: %s\n", bactext_reject_reason_name(reject_reason));
    Error_Detected = true;
}


/** Broadcast an I Am message.
 * @ingroup DMDDB
 *
 * @param buffer [in] The buffer to use for building and sending the message.
 */
void Send_I_Am2(
    uint8_t * buffer)
{
    int pdu_len = 0;
    BACNET_ADDRESS dest;
    int bytes_sent = 0;
    BACNET_NPDU_DATA npdu_data;

#if 0
    /* note: there is discussion in the BACnet committee
       that we should allow a device to reply with I-Am
       so that dynamic binding always work.  If the DCC
       initiator loses the MAC address and routing info,
       they can never re-enable DCC because they can't
       find the device with WhoIs/I-Am */
    /* are we are forbidden to send? */
    if (!dcc_communication_enabled())
        return 0;
#endif

    /* encode the data */
    pdu_len = iam_encode_pdu(buffer, &dest, &npdu_data);
    /* send data */
    bytes_sent = datalink_send_pdu(&dest, &npdu_data, &buffer[0], pdu_len);

    if (bytes_sent <= 0) {
#if PRINT_ENABLED
        fprintf(stderr, "Failed to Send I-Am Reply (%s)!\n", strerror(errno));
#endif
    }
}



void Init_AI()
{
	//there are 2 AI created for testıng
	//you can either give the name during creationg or you can give hardcoded namespace
	//in this example we will use hardcoded ones
	Analog_Input_Init();
	Analog_Input_Name_Set(0,"AI TUGRUL-1");
	Analog_Input_Name_Set(1,"AI TUGRUL-2");	
	
} 
/** Encode an I Am message to be broadcast.
 * @param buffer [in,out] The buffer to use for building the message.
 * @param dest [out] The destination address information.
 * @param npdu_data [out] The NPDU structure describing the message.
 * @return The length of the message in buffer[].
 */
int iam_encode_pdu(
    uint8_t * buffer,
    BACNET_ADDRESS * dest,
    BACNET_NPDU_DATA * npdu_data)
{
    int len = 0;
    int pdu_len = 0;
    BACNET_ADDRESS my_address;
    datalink_get_my_address(&my_address);

    datalink_get_broadcast_address(dest);
    /* encode the NPDU portion of the packet */
    npdu_encode_npdu_data(npdu_data, false, MESSAGE_PRIORITY_NORMAL);
    pdu_len = npdu_encode_pdu(&buffer[0], dest, &my_address, npdu_data);

    /* encode the APDU portion of the packet */
    len =
        iam_encode_apdu(&buffer[pdu_len], Device_Object_Instance_Number(),
        MAX_APDU, SEGMENTATION_NONE, Device_Vendor_Identifier());
    pdu_len += len;

    return pdu_len;
}


void handler_who_is2(uint8_t * service_request,
    uint16_t service_len,
    BACNET_ADDRESS * src)
{
	printf("\n handler_who_is");
	Send_I_Am2(&Handler_Transmit_Buffer[0]);
	
}
/* BACnet handler, stack init, IAm */
void StartBACnet()
{
	printf("\nStartBACnet IN");
	
    /* we need to handle who-is to support dynamic device binding */
    apdu_set_unconfirmed_handler(SERVICE_UNCONFIRMED_WHO_IS, handler_who_is2);

    /* set the handler for all the services we don't implement */
    /* It is required to send the proper reject message... */ 
    apdu_set_unrecognized_service_handler_handler
       (handler_unrecognized_service);
    /* Set the handlers for any confirmed services that we support. */
    /* We must implement read property - it's required! */
    apdu_set_confirmed_handler(SERVICE_CONFIRMED_READ_PROPERTY,
        handler_read_property);
    apdu_set_confirmed_handler(SERVICE_CONFIRMED_READ_PROP_MULTIPLE,
        handler_read_property_multiple);
    
    apdu_set_confirmed_handler(SERVICE_CONFIRMED_WRITE_PROPERTY,
        handler_write_property);
    apdu_set_confirmed_handler(SERVICE_CONFIRMED_SUBSCRIBE_COV,
        handler_cov_subscribe);    
     
    address_init();   
    bip_init(NULL); 
	 /* handle any errors coming back */
    apdu_set_abort_handler(MyAbortHandler);
    apdu_set_reject_handler(MyRejectHandler);
	//dlenv_init();

    Send_I_Am2(&Handler_Transmit_Buffer[0]);
	printf("\n StartBACnet OUT");
	
}

/* wifi events handler : start & stop bacnet with an event  */
esp_err_t wifi_event_handler(void *ctx, system_event_t *event)
{
	printf("\nwifi_event_handler event:%d",event->event_id);
	
    switch(event->event_id) {
    case SYSTEM_EVENT_STA_START:
        esp_wifi_connect();
        break;
    case SYSTEM_EVENT_STA_CONNECTED:
        break ;
    case SYSTEM_EVENT_STA_GOT_IP:
        if (xEventGroupGetBits(wifi_event_group)!=CONNECTED_BIT)
        {            
            xEventGroupSetBits(wifi_event_group, CONNECTED_BIT);
            StartBACnet();
        }
        break;
    case SYSTEM_EVENT_STA_DISCONNECTED:
        /* This is a workaround as ESP32 WiFi libs don't currently
           auto-reassociate. */
        esp_wifi_connect(); 
        xEventGroupClearBits(wifi_event_group, CONNECTED_BIT);
        bip_cleanup();
        break;
    default:
        break;
    }
    return ESP_OK;
}

/* tcpip & wifi station start */

void wifi_init_station(void)
{
	printf("\nwifi_init_station IN");

    tcpip_adapter_init();
    wifi_event_group = xEventGroupCreate();
    esp_event_loop_init(wifi_event_handler, NULL);

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    esp_wifi_init(&cfg);

    esp_wifi_set_storage(WIFI_STORAGE_RAM);
    esp_wifi_set_mode(WIFI_MODE_STA);

    esp_wifi_set_config(ESP_IF_WIFI_STA, &wifi_config);

    esp_wifi_start() ;
	printf("\nwifi_init_station OUT");

}

/* setup gpio & nv flash, call wifi init code */
void setup()
{
    gpio_pad_select_gpio(BACNET_LED);
    gpio_set_direction(BACNET_LED, GPIO_MODE_OUTPUT);

    gpio_set_level(BACNET_LED,0);

    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES) 
    {
        nvs_flash_erase();
        ret = nvs_flash_init();
    }
    wifi_init_station();    
}

/* Bacnet Task */
void BACnetTask(void *pvParameters)
{  
	printf("\n BACnetTask IN");

    uint16_t pdu_len = 0;
    BACNET_ADDRESS src = {
        0
    };
    unsigned timeout = 1;  

    // Init Bacnet objets dictionnary
    Device_Init(NULL);
    Device_Set_Object_Instance_Number(4567);
	Device_Object_Name_ANSI_Init("ESP32 WIFI TEST");
    setup();
//this will create a device with obkect id 777 and name ESP32 WIFI TEST
	
	Init_AI();
	
	
    uint32_t tickcount=xTaskGetTickCount();

    for (;;)
    {
        vTaskDelay(10 / portTICK_PERIOD_MS); // could be remove to speed the code

        // do nothing if not connected to wifi
        xEventGroupWaitBits(wifi_event_group, CONNECTED_BIT, false, true, portMAX_DELAY);
        { 
            uint32_t newtick=xTaskGetTickCount();

            // one second elapse at least (maybe much more if Wifi was deconnected for a long)
            if ((newtick<tickcount)||((newtick-tickcount)>=configTICK_RATE_HZ))
            {
                tickcount=newtick;
                dcc_timer_seconds(1);
                bvlc_maintenance_timer(1); 
                handler_cov_timer_seconds(1);
                tsm_timer_milliseconds(1000);

                // Read analog values from internal sensors
                Analog_Input_Present_Value_Set(0,temprature_sens_read());
                Analog_Input_Present_Value_Set(1,hall_sens_read());

            }

            pdu_len = datalink_receive(&src, &Rx_Buf[0], MAX_MPDU, timeout);
            if (pdu_len) 
            {                
                npdu_handler(&src, &Rx_Buf[0], pdu_len);

                if(Binary_Output_Present_Value(0)==BINARY_ACTIVE)
                    gpio_set_level(BACNET_LED,1);
                else
                    gpio_set_level(BACNET_LED,0);       
            }

            handler_cov_task();
        }
    }
}
/* Entry point */
void app_main()
{    
	printf("\n app_main IN");

    // Cannot run BACnet code here, the default stack size is to small : 4096 byte
    xTaskCreate(
        BACnetTask,     /* Function to implement the task */
        "BACnetTask",   /* Name of the task */
        10000,          /* Stack size in words */
        NULL,           /* Task input parameter */
        20,             /* Priority of the task */
        NULL);          /* Task handle. */   
}