#include "Arduino.h"
#include "Switch.h"

Switch::Switch(int pin, int pushLenght, int loopLength) {
  this->pin = pin;
  this->longPush = pushLenght / loopLength;
}

SwitchState Switch::checkSwitch() {
  int state = digitalRead(pin);

  if (state == HIGH) {
    if (pushCounter >= longPush) {
      Serial.print(pushCounter);
      Serial.print(" long\n");
      return LongPush;
    }

    pushCounter++;
  } else {
    if (pushCounter > 0 && pushCounter < longPush) {
      Serial.print(pushCounter);
      Serial.print(" short\n");
      resetCounter();
      return ShortPush;
    }

    resetCounter();
    return NoPush;
  }
}

void Switch::resetCounter() {
  pushCounter = 0;
}