#include <SoftwareSerial.h>
#include <ParallaxRFID.h>

ParallaxRFID RFIDclient;

void setup()
{
}

void loop()
{
  RFIDclient.Write(25,25,25,25,25);
}
