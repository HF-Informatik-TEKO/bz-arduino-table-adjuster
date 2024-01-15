#include "Arduino.h"
#include "Button.h"
#include "appsettings.h"


Button::Button(int pin) {
  this->pin = pin;
  longPushDuration = SWITCH_LONG_PUSH_MS / LOOP_DURATION_MS;
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
    return NoButtonState;
  }

}

void Button::resetCounter() {
  pushCounter = 0;
}