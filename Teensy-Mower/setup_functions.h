#ifndef SETUP_FUNCTIONS_H
#define SETUP_FUNCTIONS_H

#include "pin_definitions.h"
#include "robot_state_machine.h"
#include "perimeter_tracking.h"

void initializePins();
void initializeMotors();
void initializeSensors();
void initializePerimeterTracking();
void initializeBatteryMonitor();
void initializeStateMachine();
void initializeSerialCommunication();

#endif
