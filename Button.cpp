#include "Arduino.h"
#include "Button.h"

Button::Button(int pin, int longPushDuration) {
  this->pin = pin;
  this->longPushDuration = longPushDuration;
  pushCounter = 0;
  resetCounter();
  pinMode(pin, INPUT);
}

Button::Button(int pin, DurationsConfig* durationsConfig) {
  this->pin = pin;
  longPushDuration = durationsConfig->buttonLongPressMs / durationsConfig->loopDurationMs;
  pushCounter = 0;
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
  bool isPressedLong = pushCounter > longPushDuration;

  if (state == HIGH) {
    if (isPressedLong) {
      return returnState(PressedLong);
    }
    pushCounter++;
  } else {
    if (pushCounter > 0 && !isPressedLong) {
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