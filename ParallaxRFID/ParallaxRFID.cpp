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
#include "defines.h"


/// @todo: enable global debug mode to suppress serial logging (using #define RFID_DEBUG)
/// @todo: add functions to separate debugging code from functional code

/// Construct 
 ParallaxRFID::ParallaxRFID(int in,int out): _mySerial(in, out)
 {
	 _txPin=out;
	 _rxPin=in;
	 begin();
 }
 
 
void ParallaxRFID::begin()
{
	_bytesread=0;
	Serial.begin(9600);
    _mySerial.begin(9600);
    pinMode(_rxPin, INPUT);
    pinMode(_txPin, OUTPUT);
	Serial.print("begonnen");
}
 
 

void ParallaxRFID::suppressAll()
 {
  if(_mySerial.available() > 0) {
    _mySerial.read();
    ParallaxRFID::suppressAll();
  }
 }
 
 int ParallaxRFID::readRFID(int adress)
 {
  
  _mySerial.print("!RW");
  _mySerial.write(byte(RFID_READ));
  _mySerial.write(byte(adress));
 
  int one;
  int two;
  int three;
  int four;

  if(_mySerial.available() > 0) {
    _val = _mySerial.read();                       //The _mySerial.read() procedure is called, but the result is not printed because I don't want the "error message: 1" cluttering up the serial monitor
    if (_val != 1)                                 //If the error code is anything other than 1, then the RFID tag was not read correctly and any data collected is meaningless. In this case since we don't care about the resultant values they can be suppressed
      {suppressAll();}
  }
 

  if(_mySerial.available() > 0) {
    _val = _mySerial.read();
	one=_val;
	delay(250);
  }
 

  if(_mySerial.available() > 0) {
    _val = _mySerial.read();
   two=_val;
	delay(250);
  }

  if(_mySerial.available() > 0) {
    _val = _mySerial.read();
	three=_val;
	delay(250);
  }

  if(_mySerial.available() > 0) {
    _val = _mySerial.read();
	four=_val;
	delay(250);
  }
  if(one==two&&two==three&&three==four)//all off the tags will have a code like 5,5,5,5 or 6,6,6,6 or ....
	  //if tag read correct/ send the number of tag, else return false
  {
	  return one;
  }
  else
  {
	  return 0;
  }
  
 };
 
 void ParallaxRFID::writeRFID(int whichSpace,int first,int second,int third,int fourth)
 {
	 Serial.print("in schrijf functie");
	_RFID_WRITE=0x02;
  _whichSpace=whichSpace;
  _first=first;
  _second=second;
  _third=third;
  _fourth=fourth;

   int val;

  _mySerial.print("!RW");
  _mySerial.write(byte(_RFID_WRITE));
  _mySerial.write(byte(_whichSpace));
  _mySerial.write(byte(_first));
  _mySerial.write(byte(_second));
  _mySerial.write(byte(_third));
  _mySerial.write(byte(_fourth));

if(_mySerial.available() > 0) {        
    val = _mySerial.read();
    if (val == 1)                                        //If data was written successfully
      { Serial.println("Data written succesfully!");
        suppressAll();
      }
    else suppressAll();                                  //If an error occured during writing, discard all data recieved from the RFID writer
    }
delay(250);
 };
