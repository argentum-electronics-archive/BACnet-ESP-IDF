cd /D C:\Users\Sagarr\Desktop\bacnet_esp32\build || exit /b
C:\Users\Sagarr\.espressif\python_env\idf3.3_py3.7_env\Scripts\python.exe C:/Users/Sagarr/Desktop/esp-idf/tools/kconfig_new/confgen.py --kconfig C:/Users/Sagarr/Desktop/esp-idf/Kconfig --config C:/Users/Sagarr/Desktop/bacnet_esp32/sdkconfig --env "COMPONENT_KCONFIGS= C:/Users/Sagarr/Desktop/esp-idf/components/app_trace/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/aws_iot/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/bt/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/driver/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/efuse/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/esp-aws-iot/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/esp32/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/esp_adc_cal/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/esp_event/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/esp_http_client/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/esp_http_server/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/esp_https_ota/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/espcoredump/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/ethernet/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/fatfs/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/freemodbus/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/freertos/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/heap/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/libsodium/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/log/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/lwip/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/mbedtls/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/mdns/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/mqtt/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/nvs_flash/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/openssl/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/pthread/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/spi_flash/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/spiffs/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/tcpip_adapter/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/unity/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/vfs/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/wear_levelling/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/wifi_provisioning/Kconfig" --env "COMPONENT_KCONFIGS_PROJBUILD= C:/Users/Sagarr/Desktop/esp-idf/components/app_update/Kconfig.projbuild C:/Users/Sagarr/Desktop/esp-idf/components/bootloader/Kconfig.projbuild C:/Users/Sagarr/Desktop/esp-idf/components/esptool_py/Kconfig.projbuild C:/Users/Sagarr/Desktop/esp-idf/components/partition_table/Kconfig.projbuild" --env IDF_CMAKE=y --env IDF_TARGET=esp32 --output config C:/Users/Sagarr/Desktop/bacnet_esp32/sdkconfig || exit /b
C:\Users\Sagarr\.espressif\tools\cmake\3.13.4\bin\cmake.exe -E env "COMPONENT_KCONFIGS= C:/Users/Sagarr/Desktop/esp-idf/components/app_trace/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/aws_iot/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/bt/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/driver/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/efuse/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/esp-aws-iot/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/esp32/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/esp_adc_cal/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/esp_event/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/esp_http_client/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/esp_http_server/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/esp_https_ota/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/espcoredump/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/ethernet/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/fatfs/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/freemodbus/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/freertos/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/heap/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/libsodium/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/log/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/lwip/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/mbedtls/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/mdns/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/mqtt/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/nvs_flash/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/openssl/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/pthread/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/spi_flash/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/spiffs/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/tcpip_adapter/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/unity/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/vfs/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/wear_levelling/Kconfig C:/Users/Sagarr/Desktop/esp-idf/components/wifi_provisioning/Kconfig" "COMPONENT_KCONFIGS_PROJBUILD= C:/Users/Sagarr/Desktop/esp-idf/components/app_update/Kconfig.projbuild C:/Users/Sagarr/Desktop/esp-idf/components/bootloader/Kconfig.projbuild C:/Users/Sagarr/Desktop/esp-idf/components/esptool_py/Kconfig.projbuild C:/Users/Sagarr/Desktop/esp-idf/components/partition_table/Kconfig.projbuild" IDF_CMAKE=y KCONFIG_CONFIG=C:/Users/Sagarr/Desktop/bacnet_esp32/sdkconfig IDF_TARGET=esp32 C:/Users/Sagarr/.espressif/tools/mconf/v4.6.0.0-idf-20190628/mconf-idf.exe C:/Users/Sagarr/Desktop/esp-idf/Kconfig || exit /b
