#ifndef CONFIG_H
#define CONFIG_H

#define MowerName = "MatrixMOW";



#define motorSpeedMaxRpm = 30;   // motor wheel max RPM (WARNING: do not set too high, so there's still speed control when battery is low!)
#define motorSpeedMaxPwm = 108;  // motor wheel max Pwm  (8-bit PWM=255, 10-bit PWM=1023)
#define motorPowerMax = 20;    // motor wheel max power (Watt)

// motor wheel PID controller
#define motorLeftPID.Kp = 1.0;
#define motorLeftPID.Ki = 0.4;
#define motorLeftPID.Kd = 0.0;
