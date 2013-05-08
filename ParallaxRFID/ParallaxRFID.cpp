// DistanceSensor.h - Arduino library for retrieving data from Distance sensors
// Copyright 2011 Jeroen Doggen (jeroendoggen@gmail.com)
// More info: http://www.robot-electronics.co.uk/files/SRF04.pde
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
#include <SoftwareSerial.h>
#include "Arduino.h"
#include "ParallaxRFID.h"

ParallaxRFID::ParallaxRFID(int in,int out): _mySerial(in, out)
{
  _txPin=out;
  _rxPin=in;
  // 	_RFID_LEGACY=0x0F;
  // 	_RFID_WRITE =0x02;
  // 	_val = 0;
  // 	_bytesread=0;

}

/*
void ParallaxRFID::begin()
{
//     this->compassSerial = new SoftwareSerial(6, 7);
//     this->compassSerial->begin(9600);
Serial.begin(9600);
// 	mySerial.begin(9600);
pinMode(_rxPin, INPUT);
pinMode(_txPin, OUTPUT);

}

void ParallaxRFID::suppressAll()                                //suppresses the "null result" from being printed if no RFID tag is present
{
if(mySerial.available() > 0)
{ mySerial.read();
ParallaxRFID::suppressAll();
}
}

int ParallaxRFID::readRFID()
{
mySerial.print("!RW");
mySerial.write(byte(_RFID_LEGACY));

if(mySerial.available() > 0)
{          // if data available from reader

if((_val = mySerial.read()) == 10)
{   // check for header
_bytesread = 0;
while(_bytesread<10)
{              // read 10 digit code
if( mySerial.available() > 0)
{
_val = mySerial.read();
if((_val == 10)||(_val == 13))
{ // if header or stop bytes before the 10 digit reading
break;                       // stop reading
}
_code[_bytesread] = _val;         // add the digit
_bytesread++;                   // ready to read next digit
}
}

if(_bytesread == 10)
{              // if 10 digit read is complete
Serial.print("TAG code is: ");   // possibly a good TAG
Serial.println(_code);            // print the TAG code
return _code;
}
_bytesread = 0;
return 0;
delay(500);
}
}
};

void ParallaxRFID::writeRFID(int whichSpace,int first,int second,int third,int fourth)
{
_whichSpace=whichSpace;
_first=first;
_second=second;
_third=third;
_fourth=fourth;

mySerial.print("!RW");
mySerial.write(byte(_RFID_WRITE));
mySerial.write(byte(_whichSpace));
mySerial.write(byte(_first));
mySerial.write(byte(_second));
mySerial.write(byte(_third));
mySerial.write(byte(_fourth));

if(mySerial.available() > 0) {
_val = mySerial.read();
if (_val == 1)                                        //If data was written successfully
{ Serial.println("Data written succesfully!");
suppressAll();
}
else suppressAll();                                  //If an error occured during writing, discard all data recieved from the RFID writer
}
delay(250);
};
*/
