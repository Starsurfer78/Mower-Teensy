#ifndef MOTOR_H
#define MOTOR_H

class Motor {
  public:
    Motor(uint8_t _in1_pin, uint8_t _in2_pin, uint8_t _pwm_pin, float _ticks_per_meter);
    void setSpeed(float linear_speed);
    void stop();
    float getCurrentSpeed();
  private:
    uint8_t in1_pin, in2_pin, pwm_pin;
    float ticks_per_meter;
    float current_speed;
    void updateSpeed(float linear_speed);
};

#endif
