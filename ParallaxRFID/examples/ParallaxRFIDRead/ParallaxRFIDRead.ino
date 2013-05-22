// connect RFID vcc to 5V
// connect RFID SIN to pin 6
// connect RFID SOUT to pin 8
// connect RFID GND to GND


#include <SoftwareSerial.h>
#include <ParallaxRFID.h>

ParallaxRFID RFIDclient(8,6);
int x;
void setup()
{
  Serial.begin(9600);
  
}

void loop()
{
  x=RFIDclient.readRFID(4);
  if( x != 0)
  {
    Serial.print("succes");
    Serial.println(x);
  }
  delay(1000);
}
