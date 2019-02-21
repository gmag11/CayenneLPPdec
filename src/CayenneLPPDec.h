// CayenneLPPDec.h
// CayenneLPP Decoder
//
// Decodes a CayenneLPP binary buffer to JSON format
//
// https://os.mbed.com/teams/myDevicesIoT/code/Cayenne-LPP
// https://github.com/open-source-parsers/jsoncpp
//
// Copyright (c) 2018 Robbert E. Peters. All rights reserved.  
// Licensed under the MIT License. See LICENSE file in the project root for full license information.  
//
// 29 April 2018 - Initial Version
// 21 February 2019 - 0.1.0 - Ported to Arduino platform by Germán Martín
//
// Based on https://github.com/gizmocuz/CayenneLPP-Decoder

#ifndef _CAYENNELPPDEC_h
#define _CAYENNELPPDEC_h
#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#include <ArduinoJson.h>

class CayenneLPPDec
{
  public:
     static bool ParseLPP (const uint8_t *pBuffer, size_t Len, JsonArray& root);
};


#endif

