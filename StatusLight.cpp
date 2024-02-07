#include "Arduino.h"
#include "StatusLight.h"

void StatusLight::setFreeStatus() {
  green.on();
  yellow.off();
  red.off();
}

void StatusLight::setBusyStatus() {
  green.off();
  yellow.on();
  red.off();
}

void StatusLight::setErrorStatus() {
  green.off();
  yellow.off();
  red.on();
}