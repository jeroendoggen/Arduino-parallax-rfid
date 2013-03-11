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

class ParallaxRFID
{
  public:
	  ParallaxRFID(_txPin, _rxPin);

    int Read();
	void Write(int AddressTag);
    void suppressAll();

  private:
    int _txPin = 6;
	int _rxPin = 8;
	int _RFID_LEGACY = 0x0F;
	int _RFID_WRITE = 0x02;
	int _val = 0;
	char _code[11];
	int _bytesread = 0;
	int _whichSpace = 4;

};
#endif
