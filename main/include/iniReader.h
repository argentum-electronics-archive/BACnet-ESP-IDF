/*
 * File:   iniReader.h
 * Author: benmaynard
 *
 * Created on August 26, 2010, 2:49 PM
 */

#ifndef INIREADER_H
#define	INIREADER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * Parse a configuration file
 *
 * @param	fileName The name of the file to parse
 * @return	none
 */
void parseIniFile(char *fileName);


/**
 * Copy the value of the selected config item to the char pointer
 *
 * @param	char *dest The destination of the config value
 * @param	char *key The key of the config item
 * @return	int 1 on success or 0 on failure
 */

int getConfigValue(char *dest, char *key);

#endif	/* INIREADER_H */

