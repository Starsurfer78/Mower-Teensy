#ifndef Bumper_h
#define Bumper_h


class Bumper {
  public:
    Bumper();
    void init();
    bool leftTriggered();
    bool rightTriggered();
  private:
    static void leftInterruptHandler();
    static void rightInterruptHandler();
    static volatile bool _leftTriggered;
    static volatile bool _rightTriggered;
};

#endif
