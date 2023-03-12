#ifndef ROBOTCONTROL_H
#define ROBOTCONTROL_H

#include "pin_definations.h"
#include "config.h"

// Functions
void setup_robot();
void drive_forward(float distance);
void turn(float angle);

#endif
