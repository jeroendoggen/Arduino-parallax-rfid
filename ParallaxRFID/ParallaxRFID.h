// ParallaxRFID.h - Arduino library for ...
// Copyright 2011 Jeroen Doggen (jeroendoggen@gmail.com)
// More info: http://www.robot-electronics.co.uk/files/SRF04.pde
//
// Version History:
//  Version 0.1:
//
// Roadmap:
//  Version 0.2: ??
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

#ifndef ParallaxRFID_h
#define ParallaxRFID_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#include <pins_arduino.h>
#endif

#include <SoftwareSerial.h>
#include "defines.h"
 
 class ParallaxRFID
 {
   public:
     ParallaxRFID(int,int );
    void begin();

    void suppressAll();

    int readRFID(int address);
    void writeRFID(int whichSpace,int first,int second,int third,int fourth);
 
   private:
 
     int _txPin;
     int _rxPin;
     SoftwareSerial _mySerial;
    int _val;
    int _bytesread;
	int _RFID_WRITE;
    char _code[11];
    int  _whichSpace;
    int _first;
    int _second;
	int _third;
	int _fourth;
 };
 #endif
