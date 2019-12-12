/*
 * measurements.h
 *
 *  Created on: 28.06.2018
 *      Author: mn204
 */

#ifndef INCLUDE_MEASUREMENTS_H_
#define INCLUDE_MEASUREMENTS_H_

struct timespec t1, t2, clock_resolution;
long long elapsedTime;

void start_measurement(void);
void stop_measurement(char * path);


#endif /* INCLUDE_MEASUREMENTS_H_ */
