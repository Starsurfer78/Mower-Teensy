#include <Arduino.h>
#include "pin_definations.h"
#include "config.h"
#include "Encoder.h"

Encoder::Encoder() {
  count_ = 0;
  lastCount_ = 0;
  lastTime_ = micros();
  distance_ = 0;
}

void Encoder::init() {
  pinMode(LEFT_ENCODER_PIN, INPUT_PULLUP);
  pinMode(RIGHT_ENCODER_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(LEFT_ENCODER_PIN), []() {
    if (digitalRead(LEFT_ENCODER_PIN_B) == LOW) {
      count_--;
    } else {
      count_++;
    }
  }, CHANGE);
  attachInterrupt(digitalPinToInterrupt(RIGHT_ENCODER_PIN), []() {
    if (digitalRead(RIGHT_ENCODER_PIN_B) == LOW) {
      count_++;
    } else {
      count_--;
    }
  }, CHANGE);
}

void Encoder::reset() {
  count_ = 0;
  lastCount_ = 0;
  lastTime_ = micros();
  distance_ = 0;
}

int32_t Encoder::read() {
  return count_;
}

float Encoder::readDistance() {
  return distance_ / TICKS_PER_METER;
}

void Encoder::update() {
  noInterrupts();
  int32_t count = count_;
  interrupts();
  if (count != lastCount_) {
    uint32_t time = micros();
    int32_t dt = time - lastTime_;
    lastTime_ = time;
    int32_t delta = count - lastCount_;
    lastCount_ = count;
    distance_ += delta;
  }
}
