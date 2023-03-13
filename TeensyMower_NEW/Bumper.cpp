#include "Bumper.h"
#include <Arduino.h>
#include "config.h"
#include "pin_definations.h"

volatile bool Bumper::_leftTriggered = false;
volatile bool Bumper::_rightTriggered = false;

Bumper::Bumper() {}

void Bumper::init() {
  pinMode(pinBumperLeft, INPUT_PULLUP);
  pinMode(pinBumperRight, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinBumperLeft), leftInterruptHandler, CHANGE);
  attachInterrupt(digitalPinToInterrupt(pinBumperRight), rightInterruptHandler, CHANGE);
}

bool Bumper::leftTriggered() {
  if (_leftTriggered) {
    _leftTriggered = false;
    return true;
  }
  return false;
}

bool Bumper::rightTriggered() {
  if (_rightTriggered) {
    _rightTriggered = false;
    return true;
  }
  return false;
}

void Bumper::leftInterruptHandler() {
  _leftTriggered = true;
}

void Bumper::rightInterruptHandler() {
  _rightTriggered = true;
}
