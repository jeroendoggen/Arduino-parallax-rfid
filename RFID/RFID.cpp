

#include "Arduino.h"
#include <NewSoftSerial.h>
#include "RFID.h"
#define NewSoftSerial mySerial(8,6);
mySerial.begin(9600);

RFID::RFID(int Txpin , int Rxpin)
{
	 _txPin = Txpin;
	 _rxPin = Rxpin;
	 _RFID_LEGACY = 0x0F;
	 _val=0;
	 _bytesread=0;
}


//void RFID::Play()
