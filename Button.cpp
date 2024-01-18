#include "Arduino.h"
#include "Button.h"
#include "appsettings.h"

Button::Button() {
  // Empty on purpose.
}

Button::Button(int pin) {
  this->pin = pin;
  longPushDuration = SWITCH_LONG_PUSH_MS / LOOP_DURATION_MS;
  resetCounter();
  pinMode(pin, INPUT);
}

bool Button::hasStateChanged() {
  return hasChanged;
}

ButtonState Button::returnState(ButtonState state) {
    hasChanged = lastState != state;
    lastState = state;
    return state;
}

ButtonState Button::getState() {
  int state = digitalRead(pin);
  bool isPushedLong = pushCounter > longPushDuration;

  if (state == HIGH) {
    if (isPushedLong) {
      return returnState(PressedLong);
    }
    pushCounter++;
  } else {
    if (pushCounter > 0 && !isPushedLong) {
      resetCounter();
      return returnState(PressedShort);
    }
    resetCounter();
    return returnState(NoButtonState);
  }
}

void Button::resetCounter() {
  lastState = NoButtonState;
  pushCounter = 0;
}