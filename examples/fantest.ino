#include "Arduino.h"
// include the Fancontroller library
#include "FanController.h"
// include the LM35 library
#include "LM35.h"

// address of the temperature output from LM35 (analog pin 0)
const byte LM35_ADDRESS = A0;

// create an instance of the LM35 class
LM35 tempSensor = LM35(LM35_ADDRESS);

// digital pin 2 for fan control output
const byte FAN_PIN = 2;
// temperature at which to start the fan
const int FAN_TEMP_MIN = 10;
// maximum temperature when fan speed at 100%
const int FAN_TEMP_MAX = 50;

// create an instance of the FanController
FanController fan = FanController(FAN_PIN, FAN_TEMP_MIN, FAN_TEMP_MAX);

// variable to hold the temperature
float temp = 0;

void setup()
{
  // Setup the serial port for debugging
  Serial.begin(9600);

}

void loop()
{

  Serial.println("========");
  Serial.println("Fan Test");
  Serial.println("========");

  // wait for 5 seconds (for ease of reading the Serial Monitor)
  delay(5000);

  // get the temperature in celsius from the LM35
  temp = tempSensor.celsius();
  // print the temperature to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println("C");

  // print the status of the fan to the Serial Monitor
  Serial.print("Fan Status: ");
  Serial.println(fan.status());

  // wait for 5 seconds (for ease of reading the Serial Monitor)
  delay(5000);

  // turn on the fan
  fan.on();

  Serial.println("------");
  Serial.println("Fan On");
  Serial.println("------");

  // print the status of the fan to the Serial Monitor
  Serial.print("Fan Status: ");
  Serial.println(fan.status());

  // print the speed of the fan to the Serial Monitor
  Serial.print("Fan Speed: ");
  Serial.println(fan.speed());

  // wait for 5 seconds (for ease of reading the Serial Monitor)
  delay(5000);

  // turn on the fan
  fan.off();

  Serial.println("-------");
  Serial.println("Fan Off");
  Serial.println("-------");

  // print the status of the fan to the Serial Monitor
  Serial.print("Fan Status: ");
  Serial.println(fan.status());

  // print the speed of the fan to the Serial Monitor
  Serial.print("Fan Speed: ");
  Serial.println(fan.speed());

  // wait for 5 seconds (for ease of reading the Serial Monitor)
  delay(5000);

  // set the fanContoller to adjust the fan speed to the temperature
  fan.adjustToTemperature(temp);

  Serial.println("--------------");
  Serial.println("Fan Temp Sense");
  Serial.println("--------------");

  // print the status of the fan to the Serial Monitor
  Serial.print("Fan Status: ");
  Serial.println(fan.status());

  // print the speed of the fan to the Serial Monitor
  Serial.print("Fan Speed: ");
  Serial.println(fan.speed());

  // wait for 5 seconds (for ease of reading the Serial Monitor)
  delay(5000);
}
