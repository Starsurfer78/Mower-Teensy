#include "Encoder.h"
#include "pin_definations.h"
#include "config.h"

// Encoder constructor
Encoder::Encoder(int pin) {
  _pin = pin;
  _ticks = 0;
  _last_ticks = 0;
  _last_time = 0;
  _last_interrupt_time = 0;

  pinMode(_pin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(_pin), [] {
    if (digitalRead(pinOdometryLeft) == digitalRead(pinOdometryRight)) {
      encoder_left.update();
      encoder_right.update();
    } else if (digitalRead(pinOdometryLeft)) {
      encoder_left.update();
    } else {
      encoder_right.update();
    }
  }, CHANGE);
}

// Update ticks count
void Encoder::update() {
  int current_time = micros();
  _ticks++;
  if (current_time - _last_interrupt_time > 1000) {
    _last_ticks = _ticks;
    _last_time = current_time;
  }
  _last_interrupt_time = current_time;
}

// Get ticks count
long Encoder::getTicks() {
  return _last_ticks;
}

// Get RPM
float Encoder::getRPM() {
  float delta_ticks = _ticks - _last_ticks;
  float delta_time = micros() - _last_time;
  return delta_ticks / delta_time * 60000000.0 / TICKS_PER_REVOLUTION;
}

// Get speed in m/s
float Encoder::getSpeed(float wheel_circumference) {
  float delta_ticks = _ticks - _last_ticks;
  float delta_time = micros() - _last_time;
  return delta_ticks / delta_time * 1000000.0 / TICKS_PER_REVOLUTION * wheel_circumference;
}
