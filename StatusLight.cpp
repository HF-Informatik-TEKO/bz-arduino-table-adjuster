#include "StatusLight.h"

StatusLight::StatusLight(ConfigStatusLight* config) {
  red = new LED(config->pinLedRed);
  yellow = new LED(config->pinLedYellow);
  green = new LED(config->pinLedGreen);
}

void StatusLight::setFreeStatus() {
  green->on();
  yellow->off();
  red->off();
}

void StatusLight::setBusyStatus() {
  green->off();
  yellow->on();
  red->off();
}

void StatusLight::setErrorStatus() {
  green->off();
  yellow->off();
  red->on();
}