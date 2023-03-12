#include "Arduino.h"
#include "Encoder.h"
#include "pin_definations.h"
#include "config.h"

Encoder::Encoder(int pin_a) {
  _pin_a = pin_a;
}

void Encoder::setup() {
  pinMode(_pin_a, INPUT);
  _position = 0;
  _last_state = digitalRead(_pin_a);
}

int Encoder::read() {
  int state = digitalRead(_pin_a);
  if (state != _last_state) {
    if (digitalRead(_pin_b) != state) {
      _position++;
    } else {
      _position--;
    }
    _last_state = state;
  }
  return _position;
}
