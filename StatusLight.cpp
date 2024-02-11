#include "StatusLight.h"

StatusLight::StatusLight(StatusLightConfig* config) {
  red = new LED(config->red);
  yellow = new LED(config->yellow);
  green = new LED(config->green);
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