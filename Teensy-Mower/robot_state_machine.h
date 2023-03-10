#ifndef ROBOT_STATE_MACHINE_H
#define ROBOT_STATE_MACHINE_H

#include "Arduino.h"
#include "sensor_controller.h"
#include "motor_controller.h"
#include "battery_controller.h"
#include "perimeter_controller.h"
#include "setup_functions.h"

enum class RobotState {
  IDLE,
  LEAVE_STATION,
  MOWING,
  PERIMETER_TRACKING,
  SEARCH_PERIMETER,
  CHARGING,
  ERROR
};

class RobotStateMachine {
  public:
    RobotStateMachine(SensorController& sensor_controller, MotorController& motor_controller, BatteryController& battery_controller, PerimeterController& perimeter_controller, SetupFunctions& setup_functions);

    void set_mowing_time(unsigned long time_ms);
    void set_mowing_end_time(unsigned long time_ms);
    void set_start_time(unsigned long time_ms);
    void set_stop_time(unsigned long time_ms);

    RobotState get_state();
    void set_state(RobotState state);

    void run();
    void print_state();

  private:
    SensorController& _sensor_controller;
    MotorController& _motor_controller;
    BatteryController& _battery_controller;
    PerimeterController& _perimeter_controller;
    SetupFunctions& _setup_functions;

    unsigned long _mowing_time_ms;
    unsigned long _mowing_end_time_ms;
    unsigned long _start_time_ms;
    unsigned long _stop_time_ms;

    RobotState _state;
};

#endif
