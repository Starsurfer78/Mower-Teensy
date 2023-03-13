#include "config.h"

#define MowerName "MatrixMOW"
#define PCB_V103 true


const float WHEEL_BASE = 0.25;     // Wheel distance in Meter
const float ROBOT_LENGTH = 0.5; // Length of the mower robot in meters
const float TICKS_PER_REV = 1330.0;
const float WHEEL_DIAMETER = 28.0;

const int MAX_SPEED = 200;         // in RPM
const int MIN_SPEED = 50;          // in RPM

const int MAX_PWM = 180;          // Maximum Speed in PWM
const int MIN_PWM = 180;          // Minimum Speed in PWM

const float maxAcceleration = 0.5;  // Maximum acceleration in metres per second^2

const int pwmFrequency = 3200; // PWM-Frequenz


// motor wheel PID controller
#define motorLeftPID_Kp 0.5
#define motorLeftPID_Ki 0.1
#define motorLeftPID_Kd 0.2

#define motorRightPID_Kp 0.5
#define motorRightPID_Ki 0.1
#define motorRightPID_Kd 0.2


// Akku
const float batFull = 29.0;                  // How many volts does the battery have when it is full?
const float batGoHomeIfBelow = 24.0;         // At how many volts should it drive back to the station?
const float batSwitchOffIfBelow = 20.0;      // At how many volts should the robot be switched off?

//Station
#define usestation true        // true/false Did the Roboter use a Charging Station?
#define leavestationdirection right // true/false In which direction should the robot turn after it has left the station?

//Sonar
#define usessonar true        // true/false Did the Robot use Ultrasonic Sensors?
//#define sonarleftright true   // Use Sonar Left and Right?
//#define sonarcenter true      // Use Sonar Center?
const float MAX_DISTANCE_SONAR = 200;    // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.
const int OBSTACLE_DISTANCE = 30;   // Standard distance to obstacle

//Bumper
#define usesbumper true       // true/false Did the Robot use Ultrasonic Sensors?
#define sonarfront true       // Use Bumper Left and Right on Front?
#define sonarrear true        // Use Bumper Left and Right on Rear?

//GPS
#define usesgps false        // true/false Did the Robot use GPS?

//Timer
#define usestimer false       // true/false Timer to set the mowing times

//Serial Connections
#define Teensy_BAUDRATE 19200
#define ESP32Port Serial1  // Teensymower default OK for ESP32
#define ESP32_BAUDRATE 19200
#define GpsPort Serial3  // GPS 

//INA226 Config
const int inaMotorLeftAddr = 0x40;
const int inaMotorRightAddr = 0x41;
const int inaCutterAddr = 0x42;
const int inaBattAddr = 0x43;


// No changes needed ->
// Variables
float ticks_per_meter = TICKS_PER_REV / (WHEEL_DIAMETER * PI);
float max_ticks_per_second = MAX_SPEED / 60.0 * TICKS_PER_REV;
float max_linear_speed = (WHEEL_DIAMETER * PI * MAX_SPEED) / 60.0;
float wheel_circumference = (2.0 * PI * WHEEL_DIAMETER);    // Wheel circumference

/*
float calculateWheelCircumference(float wheel_radius){
    return 2.0 * PI * wheel_radius;
}
*/