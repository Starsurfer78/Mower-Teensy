#include <Wire.h>
#include "pin_definations.h"
#include "config.h"
#include "src/INA226.h"
#include "sonar.h"
#include "motors.h"
#include "RobotControl.h"
#include "Encoder.h"
#include "Motor.h"

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
  // Interrupts Encoder
  pinMode(pinOdometryLeft, INPUT);
  pinMode(pinOdometryRight, INPUT);
  //attachInterrupt(digitalPinToInterrupt(pinOdometryLeft), left_tick_isr, RISING);
  //attachInterrupt(digitalPinToInterrupt(pinOdometryRight), right_tick_isr, RISING);

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