#ifndef ENCODER_H
#define ENCODER_H

class Encoder {
  public:
    Encoder();
    void init();
    void reset();
    int32_t read();
    float readDistance();
    void update();
  private:
    volatile int32_t count_;
    volatile int32_t lastCount_;
    volatile uint32_t lastTime_;
    volatile int32_t distance_;
};

#endif