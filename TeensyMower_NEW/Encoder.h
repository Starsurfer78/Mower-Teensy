#ifndef ENCODER_H
#define ENCODER_H

#include <Arduino.h>

class Encoder {
  public:
    Encoder(uint8_t pin) : _pin(pin) {}
    void init();
    void reset();
    int32_t get_ticks();
    float get_distance();

  private:
    uint8_t _pin;
    volatile int32_t _ticks = 0;
    int32_t _last_ticks = 0;
    static const float TICKS_PER_REV = 720.0;
    static const float WHEEL_DIAMETER = 66.0;
    static const float WHEEL_CIRCUMFERENCE;
    static const float MM_PER_TICK;
    static void _interrupt_handler();
};

#endif