# CayenneLPP decoder

## Introduction

CayenneLPP is a format designed by [myDevices](https://mydevices.com/about/) to integrate LoRaWan nodes into their IoT platform [Cayenne](https://mydevices.com/cayenne/features/). It is used to send sensor data in a packed way to [The Things Network platform](https://www.thethingsnetwork.org). You can read more on https://mydevices.com/cayenne/docs/lora/#lora-cayenne-low-power-payload

Most of this library code is based on [Gizmocuz's CayeneLPPDecoder](https://github.com/gizmocuz/CayenneLPP-Decoder). This is a generic C++ based decoder. My work here was to adapat his code to Arduino platform.

## Description
CayenneLPP format is a quite well optimized way to send sensor data over low bit rate connection, like LoRa. You may find, probably, a better way for your specific project but CayenneLPP is a standarized and proven format that packs data in a suffiient way. It implements basic sensor types specified by [OMA SpecWorks](https://www.omaspecworks.org), formerly IPSO Alliance.

For instance, it can transmit GPS data in 11 bytes, or 8 port digital I/O in 4 bytes.

In addition, it supports multichannel data. It means that you can use it on multisensor devices.

This decoder converts a CayenneLPP formatted buffer into a JSON array.

Basic code structure is like this:

```
StaticJsonBuffer<512> jsonBuffer; // Create a Json buffer big enough. You can use https://arduinojson.org/v5/assistant/ to do a calculation
JsonArray& root = jsonBuffer.createArray (); // Create an array to parse data to
CayenneLPPDec::ParseLPP (buffer, len, root); // Convert the data
```

For data encoding on any Arduino supported board you may use [CayenneLPP Encoder library](https://github.com/sabas1080/CayenneLPP).

## Examples

Please check examples folder into repository source code.

## Other libraries needed

In order to use **CayenneLPPdec** You will need these two libraries:

- [ArduinoJSON](https://arduinojson.org). (Please use version > 6.10.0)
- [CayenneLPP encoder library](https://github.com/sabas1080/CayenneLPP) for data type definition.
