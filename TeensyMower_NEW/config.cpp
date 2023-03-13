#include "config.h"

// Global Configuration Variables
const float WHEEL_BASE = 0.52;                  // Wheel distance in Meter
const float ROBOT_LENGTH = 0.75;              // Length of the mower robot in meters
const float TICKS_PER_REV = 128;              // Number of ticks per wheel revolution
const float WHEEL_DIAMETER = 0.25;           // Diameter of the wheel in meter
const int MAX_SPEED = 3600;                        // in RPM
const int MIN_SPEED = 600;                         // in RPM
const int MAX_PWM = 200;                           // Maximum Speed in PWM
const int MIN_PWM = 0;                             // Minimum Speed in PWM
const float maxAcceleration = 1.0;         // Maximum acceleration in metres per second^2
const int pwmFrequency = 244;                    // PWM frequency in Hz
const float batFull = 13.8;                         // How many volts does the battery have when it is full?
const float batGoHomeIfBelow = 12.5;        // At how many volts should it drive back to the station?
const float batSwitchOffIfBelow = 11.5;     // At how many volts should the robot be switched off?
const bool usestation = false;                       // true/false Did the Roboter use a Charging Station?
const bool leavestationdirection = false;  // true/false In which direction should the robot turn after it has left the station?
const bool usessonar = false;                       // true/false Did the Robot use Ultrasonic Sensors?
const float MAX_DISTANCE_SONAR = 400.0; // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
const int OBSTACLE_DISTANCE = 30;             // Standard distance to obstacle
const bool usesbumper = true;                      // true/false Did the Robot use Bumper Sensors?
const bool sonarfront = false;                     // Use Bumper Left and Right on Front?
const bool sonarrear = false;                      // Use Bumper Left and Right on Rear?
const bool usesgps = false;                        // true/false Did the Robot use GPS?
const bool usestimer = false;                      // true/false Timer to set the mowing times
const int Teensy_BAUDRATE = 115200;
const HardwareSerial& ESP32Port = Serial2; // Teensymower default OK for ESP32
const int ESP32_BAUDRATE = 115200;
const HardwareSerial& GpsPort = Serial1; // GPS 
const int inaMotorLeftAddr = 0x41;
const int inaMotorRightAddr = 0x40;
const int inaCutterAddr = 0x45;
const int inaBattAddr = 0x40;

const int ticks_per_meter = (TICKS_PER_REV * 100) / (WHEEL_DIAMETER * PI); // Ticks per meter
const int max_ticks_per_second = (MAX_SPEED * TICKS_PER_REV) / 60;        // Max ticks per second
const int max_linear_speed = (WHEEL_DIAMETER * PI * MAX_SPEED) / 60;      // Max linear speed
const int wheel_circumference = (2.0 * PI * WHEEL_DIAMETER);            // Wheel circumference
