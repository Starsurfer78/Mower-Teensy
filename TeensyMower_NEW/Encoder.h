#ifndef ENCODER_H
#define ENCODER_H

class Encoder {
  public:
    Encoder(int pin_a);
    void setup();
    int read();
  private:
    int _pin_a;
    int _position;
    int _last_state;
};

#endif
