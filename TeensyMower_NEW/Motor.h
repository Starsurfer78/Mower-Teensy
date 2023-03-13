#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor {
  public:
    Motor(int pwmPin, int dirPin1, int dirPin2);
    void setSpeed(float speed);
    void setDirection(boolean direction);
    void stop();

  private:
    int _pwmPin;
    int _dirPin1;
    int _dirPin2;
};

#endif

