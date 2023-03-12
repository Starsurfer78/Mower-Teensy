#ifndef ENCODER_H
#define ENCODER_H

class Encoder {
  public:
    Encoder(int pin);
    void update();
    long getTicks();
    float getRPM();
    float getSpeed(float wheel_circumference);

  private:
    int _pin;
    volatile long _ticks;
    volatile long _last_ticks;
    volatile long _last_time;
    volatile long _last_interrupt_time;
};

#endif
