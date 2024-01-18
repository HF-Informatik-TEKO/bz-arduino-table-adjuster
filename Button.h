#ifndef BUTTON_H
#define BUTTON_H

#include "ButtonState.h"

class Button {
  private:
    ButtonState lastState;
    int pin;
    int longPushDuration;
    int pushCounter;
    bool hasChanged;

    ButtonState returnState(ButtonState state);
    void resetCounter();

  public:
    Button();
    Button(int pin);
    ButtonState getState();
    bool hasStateChanged();
};

#endif