#include <Arduino.h>
#include "config.h"
#include "pin_definations.h"
#include "Bumper.h"
#include "Ultrasonic.h"
#include "Motor.h"


Motor leftMotor(pinMotorLeftEnable, pinMotorLeftDir, pinMotorLeftPWM, TICKS_PER_METER);
Motor rightMotor(pinMotorRightEnable, pinMotorRightDir, pinMotorRightPWM, TICKS_PER_METER);
Ultrasonic leftSonar(pinSonarLeftTrigger, pinSonarLeftEcho);
Ultrasonic rightSonar(pinSonarRightTrigger, pinSonarRightEcho);
Bumper bumper;


void setup() {
  Serial.begin(9600);
  while (!Serial); // Wait for Serial to be ready
  bumper.init(); // Initialize Bumper
}


void loop() {
  // Read Bumper and Ultrasonic Sensor Data
  bool leftBumper = bumper.leftTriggered();
  bool rightBumper = bumper.rightTriggered();
  uint16_t leftDistance = leftSonar.getDistance();
  uint16_t rightDistance = rightSonar.getDistance();

  // Print Sensor Data
  Serial.print("Left Distance: ");
  Serial.print(leftDistance);
  Serial.print("cm - Right Distance: ");
  Serial.print(rightDistance);
  Serial.print("cm - Left Bumper: ");
  Serial.print(leftBumper);
  Serial.print(" - Right Bumper: ");
  Serial.println(rightBumper);

  // Perform Motor Control
  // Drive forward for 1 second
  leftMotor.setSpeed(150);
  rightMotor.setSpeed(150);
  delay(1000);

  // Turn right for 1 second
  leftMotor.setSpeed(150);
  rightMotor.setSpeed(-150);
  delay(1000);

  // Stop for 1 second
  leftMotor.stop();
  rightMotor.stop();
  delay(1000);
}
