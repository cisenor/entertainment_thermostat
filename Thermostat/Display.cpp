#include "Arduino.h"
#include "Display.h"
#include <Wire.h>

const byte s7sAddress = 0x71;

Display::Display()
{
  Wire.begin();
}

void Display::clear()
{
  Wire.beginTransmission(s7sAddress);
  Wire.write(0x76);  // Clear display command
  Wire.endTransmission();
}

void Display::setBrightness(byte value)
{
  Wire.beginTransmission(s7sAddress);
  Wire.write(0x7A);  // Set brightness command byte
  Wire.write(value);  // brightness data byte
  Wire.endTransmission();
}

void Display::setDecimal(byte decimals)
{
  Wire.beginTransmission(s7sAddress);
  Wire.write(0x77);
  Wire.write(decimals);
  Wire.endTransmission();
}

void Display::write(String toSend)
{
  while (toSend.length() < 3){
    // Left pad
    toSend = " " + toSend;
  }
  Wire.beginTransmission(s7sAddress);
  for (int i=0; i<4; i++)
  {
    Wire.write(toSend[i]);
  }
  Wire.endTransmission();
}