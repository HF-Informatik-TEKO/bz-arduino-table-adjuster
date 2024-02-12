#ifndef SERVOCONFIG_H
#define SERVOCONFIG_H

#include "ButtonState.h"

class ServoConfig {
  public:
    int pin = 22;
    int upPos = 120;
    int stopPos = 90;
    int downPos = 50;

    ServoConfig() {}
};

#endif