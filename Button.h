#include "ButtonState.h"

class Button {
  private:
    int pin;
    int longPushDuration;
    int pushCounter;
    
    void resetCounter();

  public:
    Button(int pin, int pressDuration, int loopDuration);
    ButtonState getState();
};