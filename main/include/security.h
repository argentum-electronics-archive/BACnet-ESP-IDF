/*
 * security.h
 *
 *  Created on: 03.05.2018
 *      Author: mn204
 */

#ifndef INCLUDE_SECURITY_H_
#define INCLUDE_SECURITY_H_

#include <stdio.h>
#include "bacdef.h"
#include "bacsec.h"
#include "npdu.h"

extern BACNET_SECURITY_WRAPPER wrapper;

/* function to set npdu data for secured message */
int set_npdu_data(BACNET_NPDU_DATA * npdu_data,
	BACNET_NETWORK_MESSAGE_TYPE type);
/* function to set security wrapper fields */
int set_security_wrapper_fields_static(uint32_t device_id,
	BACNET_ADDRESS * dest,
	BACNET_ADDRESS * src);

int initialize_security_wrapper(void);

#endif /* INCLUDE_SECURITY_H_ */
