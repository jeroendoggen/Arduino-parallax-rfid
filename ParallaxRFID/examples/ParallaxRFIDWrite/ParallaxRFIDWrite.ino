#include <SoftwareSerial.h>
#include <ParallaxRFID.h>
 ParallaxRFID RFIDclient(8,6);

void setup()
{
}

void loop()
{
  RFIDclient.writeRFID(4,25,25,25,25);
}
