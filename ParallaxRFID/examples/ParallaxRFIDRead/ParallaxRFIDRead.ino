#include <SoftwareSerial.h>
#include <ParallaxRFID.h>

ParallaxRFID RFIDclient;

void setup()
{
  Serial.begin(9600);
  Serial.print("hello world");
}

void loop()
{
  RFIDclient.Read();
}
