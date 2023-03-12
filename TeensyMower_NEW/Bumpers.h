#ifndef BUMPERS_H
#define BUMPERS_H

#include "Arduino.h"
#include "config.h"
#include "pin_definations.h"

class Bumpers {
  public:
    Bumpers();
    void init();
    bool read_left_bumper();
    bool read_right_bumper();
  private:
    static void left_bumper_isr();
    static void right_bumper_isr();
};

#endif

