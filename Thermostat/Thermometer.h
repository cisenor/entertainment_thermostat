#ifndef Thermometer_h
#define Thermometer_h

class Thermometer
{
  public:
    Thermometer(int read, int signal);
    float read();
  private:
    int _read;
    int _signal;
};

#endif