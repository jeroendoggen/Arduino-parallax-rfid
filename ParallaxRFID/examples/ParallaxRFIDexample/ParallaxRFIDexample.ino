#include <SoftwareSerial.h>
#include <ParallaxRFID.h>

ParallaxRFID RFIDclient;

void setup()
{
}

void loop()
{
  RFIDclient.Read();
}
