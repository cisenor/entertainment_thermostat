#include "Arduino.h"
#include "Thermometer.h"
int _read;
int _signal;

int Vo;
float R1 = 10380;
float logR2, R2, T;
float A = -7.591709487e-03, B = 16.20271427e-04, C = -49.73858390e-07;  // Steinhart-Hart and Hart Coefficients

Thermometer::Thermometer(int read, int signal)
{
    _read = read;
    _signal = signal;
    Serial.begin(9600);
    Serial.println("Thermometer initialized.");
}

float Thermometer::read()
{  
  Vo = analogRead(_read);
  R2 = R1* (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (A + B*logR2 + C*logR2*logR2*logR2));  // Steinhart and Hart Equation. T  = 1 / {A + B[ln(R)] + C[ln(R)]^3}
  T =  T - 273.15;
  return T * 100;
}