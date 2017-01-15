#include "FanController.h"

FanController::FanController(byte fanPin, int minTempC, int maxTempC) {
  _fanPin = fanPin;
  _minTempCelsius = minTempC;
  _maxTempCelsius = maxTempC;
  _fanStatus = 0;
  _fanSpeed = 0;
}

void FanController::adjustToTemperature(float tempCelsius){
  if (tempCelsius < _minTempCelsius) {
    // if temperature is lower than the minimum temperature, turn the fan off
    off();
  } else if ((tempCelsius >= _minTempCelsius) && (tempCelsius <= _maxTempCelsius)){
    // if temperature is between the min and max temp
    // map the fan to a suitable speed
    _fanSpeed = map(tempCelsius, _minTempCelsius, _maxTempCelsius, 100, 255);
    analogWrite(_fanPin, _fanSpeed);
    _fanStatus = 1;
  } else {
    // if the max temp is exceeded, run the fan at max speed
    on();
  }
}

void FanController::off(){
  _fanSpeed = 0;
  digitalWrite(_fanPin, LOW);
  _fanStatus = 0;
}

void FanController::on(){
  _fanSpeed = 255;
  analogWrite(_fanPin, _fanSpeed);
  _fanStatus = 2;
}

int FanController::status(){
  return _fanStatus;
}

int FanController::speed(){
  return _fanSpeed;
}
