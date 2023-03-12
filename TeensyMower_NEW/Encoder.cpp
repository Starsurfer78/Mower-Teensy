#include <Arduino.h>
#include "pin_definations.h"
#include "config.h"
#include "Encoder.h"

const float Encoder::WHEEL_CIRCUMFERENCE = PI * WHEEL_DIAMETER;
const float Encoder::MM_PER_TICK = WHEEL_CIRCUMFERENCE / TICKS_PER_REV;

void Encoder::init() {
  pinMode(_pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(_pin), _interrupt_handler, CHANGE);
}

void Encoder::reset() {
  noInterrupts();
  _ticks = 0;
  _last_ticks = 0;
  interrupts();
}

int32_t Encoder::get_ticks() {
  noInterrupts();
  int32_t ticks = _ticks;
  interrupts();
  return ticks;
}

float Encoder::get_distance() {
  return get_ticks() * MM_PER_TICK;
}

void Encoder::_interrupt_handler() {
  static int8_t last_a = 0;
  static int8_t last_b = 0;

  int8_t a = digitalRead(pinOdometryLeft);
  int8_t b = digitalRead(pinOdometryRight);

  if (a == last_a && b == last_b) {
    return;
  }

  if (a == b) {
    Encoder::_ticks++;
  } else {
    Encoder::_ticks--;
  }

  last_a = a;
  last_b = b;
}
