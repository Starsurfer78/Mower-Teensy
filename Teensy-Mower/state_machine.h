#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

enum State {
  IDLE,
  CHARGING,
  MOWING,
  LEAVE_STATION,
  PERI_TRACK
};

class StateMachine {
  public:
    StateMachine();
    void setState(State state);
    State getState();
    bool stateChanged();
  private:
    State currentState;
    State lastState;
    bool changed;
};

#endif
