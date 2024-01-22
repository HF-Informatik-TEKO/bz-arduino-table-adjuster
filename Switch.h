#include "SwitchState.h"

class Switch {
  private:
    int pin;
    int longPush;
    int pushCounter;


  public:
    Switch(int pin, int pushLenght, int loopLength);
    SwitchState checkSwitch();
    void resetCounter();
};