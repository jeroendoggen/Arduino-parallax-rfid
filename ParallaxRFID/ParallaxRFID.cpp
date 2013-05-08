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
  _rxPin=in;
  _txPin=out;
  _bytesread=0;
}

void ParallaxRFID::begin()
{
  Serial.begin(9600);
  _mySerial.begin(9600);
  pinMode(_rxPin, INPUT);
  pinMode(_txPin, OUTPUT);
  //   while(true){
  //   Serial.println(_rxPin);
  //   delay(100);
  // //   _mySerial.writeRFID(9600);
  //   }
}

//suppresses the "null result" from being printed if no RFID tag is present
void ParallaxRFID::suppressAll()
{
  if(_mySerial.available() > 0) {
    _mySerial.read();
    ParallaxRFID::suppressAll();
  }
}

int ParallaxRFID::readRFID()
{
  int val;
  _mySerial.print("!RW");
  _mySerial.write(byte(RFID_READ));
  /// @TODO: why 32?
  //   _mySerial.write(byte(32));
  _mySerial.write(byte(32));

  if(_mySerial.available() > 0) {
    val = _mySerial.read();                       //The _mySerial.read() procedure is called, but the result is not printed because I don't want the "error message: 1" cluttering up the serial monitor
    if (val != 1)                                 //If the error code is anything other than 1, then the RFID tag was not read correctly and any data collected is meaningless. In this case since we don't care about the resultant values they can be suppressed
      {suppressAll();}
  }

  if(_mySerial.available() > 0) {
    val = _mySerial.read();
    Serial.print("1st:");
    Serial.println(val, HEX);
  }

  if(_mySerial.available() > 0) {
    val = _mySerial.read();
    Serial.print("2nd:");
    Serial.println(val, HEX);
  }

  if(_mySerial.available() > 0) {
    val = _mySerial.read();
    Serial.print("3rd:");
    Serial.println(val, HEX);
  }

  if(_mySerial.available() > 0) {
    val = _mySerial.read();
    Serial.print("4th:");
    Serial.println(val, HEX);
    Serial.println("-----------------");
  }
};

void ParallaxRFID::writeRFID(int whichSpace,int first,int second,int third,int fourth)
{
  _whichSpace=whichSpace;
  _first=first;
  _second=second;
  _third=third;
  _fourth=fourth;

  _mySerial.print("!RW");
  _mySerial.write(byte(_RFID_WRITE));
  _mySerial.write(byte(_whichSpace));
  _mySerial.write(byte(_first));
  _mySerial.write(byte(_second));
  _mySerial.write(byte(_third));
  _mySerial.write(byte(_fourth));

  if(_mySerial.available() > 0) {
    _val = _mySerial.read();
    if (_val == 1) {                              //If data was written successfully
      Serial.println("Data written succesfully!");
      suppressAll();
    }
    else suppressAll();                           //If an error occured during writing, discard all data recieved from the RFID writer
  }
};
