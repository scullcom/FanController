#ifndef FanController_h
#define FanController_h

#include <Arduino.h>

class FanController {
  public:
    FanController(byte fanPin, int minTempC, int maxTempC);
    void adjustToTemperature(float tempCelsius);
    void on();
    void off();
    int status();
    int speed();
  private:
    byte _fanPin;
    int _minTempCelsius;
    int _maxTempCelsius;
    int _fanStatus;
    int _fanSpeed;

};
#endif
