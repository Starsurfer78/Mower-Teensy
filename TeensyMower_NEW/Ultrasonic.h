#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include "src/NewPing.h"

class Ultrasonic {
  private:
    uint8_t triggerPin;
    uint8_t echoPin;
    NewPing sonar;

  public:
    Ultrasonic(uint8_t triggerPin, uint8_t echoPin);
    uint16_t getDistance();
};

#endif

