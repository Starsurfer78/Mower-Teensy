#ifndef SONAR_H
#define SONAR_H

#include <Arduino.h>
#include "pin_definations.h"
#include "config.h"

#define MAX_DISTANCE 120 //TODO

extern int distance;

void readSonarDistances();

#endif


