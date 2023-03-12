#include "Bumpers.h"

volatile bool left_bumper_pressed = false;
volatile bool right_bumper_pressed = false;

Bumpers::Bumpers() {}

void Bumpers::init() {
  pinMode(pinBumperLeft, INPUT_PULLUP);
  pinMode(pinBumperRight, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(pinBumperLeft), Bumpers::left_bumper_isr, FALLING);
  attachInterrupt(digitalPinToInterrupt(pinBumperRight), Bumpers::right_bumper_isr, FALLING);
}

bool Bumpers::read_left_bumper() {
  return left_bumper_pressed;
}

bool Bumpers::read_right_bumper() {
  return right_bumper_pressed;
}

void Bumpers::left_bumper_isr() {
  left_bumper_pressed = true;
}

void Bumpers::right_bumper_isr() {
  right_bumper_pressed = true;
}
