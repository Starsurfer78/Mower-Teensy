#include <Wire.h>
#include "pin_definations.h"
#include "config.h"
#include "src/INA226/INA226.h"
#include "src/NewPing/NewPing.h"



//NewPing for the Ultrasonic Sensors
NewPing sonar_left(pinSonarLeftTrigger, pinSonarLeftEcho, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
NewPing sonar_right(pinSonarRightTrigger, pinSonarRightEcho, MAX_DISTANCE);

void setup() {
  Wire.begin();
  // Start the serial connection to the ESP32
  Serial.begin(19200);
  //ESP32Port.begin(19200);
  //Initialize all pins as outputs or inputs
  configurePins();

}

void loop() {
  // put your main code here, to run repeatedly:

}

void configurePins() {
  // Motor driver pins
  pinMode(pinMotorLeftPWM, OUTPUT);
  pinMode(pinMotorLeftDir, OUTPUT);
  pinMode(pinMotorRightPWM, OUTPUT);
  pinMode(pinMotorRightDir, OUTPUT);
  pinMode(pinMotorMowPWM, OUTPUT);
  pinMode(pinMotorMowDir, OUTPUT);

  // Bumper pins
  if (usesbumper) {
    pinMode(pinBumperLeft, INPUT_PULLUP);
    pinMode(pinBumperRight, INPUT_PULLUP);
    pinMode(pinBumperRearLeft, INPUT_PULLUP);
    pinMode(pinBumperRearRight, INPUT_PULLUP);
  }

  // Sonar pins
  if (usessonar) {
    pinMode(pinSonarLeftTrigger, OUTPUT);
    pinMode(pinSonarLeftEcho, INPUT);
    pinMode(pinSonarRightTrigger, OUTPUT);
    pinMode(pinSonarRightEcho, INPUT);
  }

  // GPS pins
  if (usesgps) {
    //pinMode(GPS_ENABLE_PIN, OUTPUT);
    //pinMode(GPS_TX_PIN, OUTPUT);
    //pinMode(GPS_RX_PIN, INPUT);
  }

  // Battery voltage monitoring pin
  //analogReadResolution(12);
  //pinMode(BATTERY_MONITOR_PIN, INPUT);

  // Debug LED pin
  //pinMode(DEBUG_LED_PIN, OUTPUT);
}