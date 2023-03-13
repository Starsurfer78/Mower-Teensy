#include "Motor.h"

Motor::Motor(int pwmPin, int dirPin1, int dirPin2) {
  _pwmPin = pwmPin;
  _dirPin1 = dirPin1;
  _dirPin2 = dirPin2;

  pinMode(_pwmPin, OUTPUT);
  pinMode(_dirPin1, OUTPUT);
  pinMode(_dirPin2, OUTPUT);
}

void Motor::setSpeed(float speed) {
  if (speed > 1.0) speed = 1.0;
  if (speed < -1.0) speed = -1.0;

  int pwmValue = map(abs(speed) * 100, 0, 100, 0, 255);
  analogWrite(_pwmPin, pwmValue);

  if (speed >= 0) {
    digitalWrite(_dirPin1, HIGH);
    digitalWrite(_dirPin2, LOW);
  } else {
    digitalWrite(_dirPin1, LOW);
    digitalWrite(_dirPin2, HIGH);
  }
}

void Motor::setDirection(boolean direction) {
  if (direction) {
    digitalWrite(_dirPin1, HIGH);
    digitalWrite(_dirPin2, LOW);
  } else {
    digitalWrite(_dirPin1, LOW);
    digitalWrite(_dirPin2, HIGH);
  }
}

void Motor::stop() {
  analogWrite(_pwmPin, 0);
}
