

#ifndef RFID_h
#define RFID_h



#include "Arduino.h"
#include <NewSoftSerial.h>

class RFID{
  
	public:
    
		RFID(int Txpin,int Rxpin);
		
		

	private:
		int _txPin;
		int _rxPin;
		int _RFID_LEGACY;
		int _val;
		char _code[11];
		int _bytesread;

		
};



#endif

