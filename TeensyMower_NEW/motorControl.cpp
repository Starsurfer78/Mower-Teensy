#include "motorControl.h"
#include <Arduino.h>
#include "config.h"
#include "pin_definations.h"

int currentSpeedLeft = 0;
int currentSpeedRight = 0;

void setSpeedLeft(int speed) {
if (speed > MAX_SPEED) {
speed = MAX_SPEED;
} else if (speed < -MAX_SPEED) {
speed = -MAX_SPEED;
}
currentSpeedLeft = speed;
if (currentSpeedLeft > 0) {
digitalWrite(pinMotorLeftDir, HIGH);
} else {
digitalWrite(pinMotorLeftDir, LOW);
currentSpeedLeft = -currentSpeedLeft;
}
analogWrite(pinMotorLeftPWM, map(currentSpeedLeft, 0, MAX_SPEED, MIN_PWM, MAX_PWM));
}

void setSpeedRight(int speed) {
if (speed > MAX_SPEED) {
speed = MAX_SPEED;
} else if (speed < -MAX_SPEED) {
speed = -MAX_SPEED;
}
currentSpeedRight = speed;
if (currentSpeedRight > 0) {
digitalWrite(pinMotorRightDir, LOW);
} else {
digitalWrite(pinMotorRightDir, HIGH);
currentSpeedRight = -currentSpeedRight;
}
analogWrite(pinMotorRightPWM, map(currentSpeedRight, 0, MAX_SPEED, MIN_PWM, MAX_PWM));
}

void setSpeed(int speedLeft, int speedRight) {
setSpeedLeft(speedLeft);
setSpeedRight(speedRight);
}

void motorForward() {
setSpeed(MAX_SPEED, MAX_SPEED);
}

void motorBackward() {
setSpeed(-MAX_SPEED, -MAX_SPEED);
}

void motorLeft() {
setSpeed(-MAX_SPEED, MAX_SPEED);
}

void motorRight() {
setSpeed(MAX_SPEED, -MAX_SPEED);
}

void motorStop() {
setSpeed(0, 0);
}

void initMotorControl() {
pinMode(pinMotorLeftEnable, OUTPUT);
pinMode(pinMotorLeftPWM, OUTPUT);
pinMode(pinMotorLeftDir, OUTPUT);
pinMode(pinMotorRightEnable, OUTPUT);
pinMode(pinMotorRightPWM, OUTPUT);
pinMode(pinMotorRightDir, OUTPUT);
digitalWrite(pinMotorLeftEnable, HIGH);
digitalWrite(pinMotorRightEnable, HIGH);
analogWriteFrequency(pinMotorLeftPWM, pwmFrequency);
analogWriteFrequency(pinMotorRightPWM, pwmFrequency);
}
