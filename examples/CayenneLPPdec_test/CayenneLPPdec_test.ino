#include <CayenneLPPDec.h>

#include <CayenneLPP.h>
#include "helperFunctions.h"

void setup () {
    Serial.begin (115200); Serial.println (); Serial.println ();

    // First, we create a CayenneLPP buffer to hold test data to decode
    CayenneLPP lpp (51);

    lpp.reset ();

    // Fill CayenneLPP buffer with some data
    lpp.addTemperature (1,25.564);
    lpp.addUnixTime (2, millis());
    lpp.addGPS (3, 4.34, 40.22, 755);

    uint8_t *buffer = lpp.getBuffer ();
    uint16_t len = lpp.getSize ();

    // Dump buffer content for debugging
    Serial.printf ("LPP Buffer: %s\n\n", printHexBuffer (buffer, len));

    // Create a Json buffer big enough. You can use https://arduinojson.org/v5/assistant/ to do a calculation
    StaticJsonBuffer<512> jsonBuffer;

    // Create an array to parse data to
    JsonArray& root = jsonBuffer.createArray ();

    // Call parser
    CayenneLPPDec::ParseLPP (buffer, len, root);

    // Print JSON data to serial
    root.prettyPrintTo (Serial);

}

void loop () {

}