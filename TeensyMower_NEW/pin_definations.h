// Pin definitions for Teensy 4.1
#ifndef PIN_DEFINATIONS_H
#define PIN_DEFINATIONS_H

// Pins Motor Driver LEFT
#define pinMotorLeftEnable 5    // EN motors enable
#define pinMotorLeftPWM 7       // M1_IN1 left motor PWM pin
#define pinMotorLeftDir 6       // M1_IN2 left motor Dir pin

// Pins Motor Driver RIGHT
#define pinMotorRightEnable 2   // EN motors enable
#define pinMotorRightPWM 4      // M2_IN1 right motor PWM pin
#define pinMotorRightDir 3      // M2_IN2 right motor Dir pin
#define pinMotorMowEnable 8     // EN mower motor enable      (if using MOSFET/L298N, keep unconnected)

// Pins Motor Cuter Driver
#define pinMotorMowPWM 10       // M1_IN1 mower motor PWM pin (if using MOSFET, use this pin)
#define pinMotorMowDir 9        // M1_IN2 mower motor Dir pin (if using MOSFET, keep unconnected)

//Endoder Pins Motor Left/Right
#define pinOdometryLeft 12    // left Encoder Sensor
#define pinOdometryRight 11   // Right Encoder Sensor

//Pins Bumper (Microswitch)
#define pinBumperLeft 35        // Bumper FRONT LEFT
#define pinBumperRight 36       // Bumper FRONT RIGHT
#define pinBumperRearLeft 30    // Bumper REAR LEFT
#define pinBumperRearRight 31   // Bumper REAR RIGHT

//Pins Ultrasonic Sensors (HC-SR04)
#define pinSonarRightTrigger 29  //Trigger RIGHT
#define pinSonarRightEcho A13    //Echo RIGHT
#define pinSonarLeftTrigger 28   //Trigger LEFT
#define pinSonarLeftEcho A12     //Echo LEFT

//Pins Perimeter Sensor (LM386)
#define pinPerimeterRight A8    //Perimeter RIGHT
#define pinPerimeterLeft A9     //Perimeter LEFT

// BUZZER
#define pinBuzzer 37

//Start/Stop Butten (NC)
#define pinButton 38             // digital ON/OFF button

//Rain Sensor Pin
#define pinRain 39                 // rain sensor

//PowerPCB PINS
#define pinBatterySwitch 33     // battery-OFF switch
#define pinChargeEnable 34      // charge relay

#define pinCover A17            // cover contact


#if defined (PCB_V103)  // here all setting for pcb1.03
#define pinMotorLeftBrake  A16   //Motor LEFT Break
#define pinMotorRightBrake  32   //Motor RIGHT Break
#define pinMotorMowBrake 13      //Motor Cutter Break
#define pinUserOut1 13    //Free
#define pinUserOut2 13    //Free
#define pinUserOut3 13    //Free
#endif

#endif
