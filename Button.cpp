#include "Arduino.h"
#include "Button.h"


Button::Button(int pin, int pressDuration, int loopDuration) {
  this->pin = pin;
  longPushDuration = pressDuration / loopDuration;
  resetCounter();
  pinMode(pin, INPUT);
}

ButtonState Button::getState() {
  int state = digitalRead(pin);
  bool isPushedLong = pushCounter > longPushDuration;

  if (state == HIGH) {
    if (isPushedLong) {
      Serial.print(pushCounter);
      Serial.print(" long\n");
      return PressedLong;
    }
    pushCounter++;
  } else {
    if (pushCounter > 0 && !isPushedLong) {
      Serial.print(pushCounter);
      Serial.print(" short\n");
      resetCounter();
      return PressedShort;
    }

    resetCounter();
    return None;
  }

}

void Button::resetCounter() {
  pushCounter = 0;
}