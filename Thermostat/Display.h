#ifndef Display_h
#define Display_h

class Display
{
  public:
    Display();
    void write(String text);
    void clear();
    void setBrightness(byte value);
    void setDecimal(byte decimals);
};

#endif
