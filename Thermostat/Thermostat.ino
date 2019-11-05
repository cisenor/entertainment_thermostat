#include "Display.h"
#include "Thermometer.h"

Display display;
Thermometer thermometer(A0, A1);
unsigned int counter;

void setup()
{
  display.setDecimal(0b00000010);
}

void loop()
{
  float t = thermometer.read();
  display.write(String(t));
  delay(1000);
}
