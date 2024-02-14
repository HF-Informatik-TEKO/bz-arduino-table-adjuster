#ifndef CONFIGSERVO_H
#define CONFIGSERVO_H

#include "ButtonState.h"

class ConfigServo {
  public:
    int pin = 22;
    int upPos = 120;
    int stopPos = 90;
    int downPos = 50;

    ConfigServo() {}
};

#endif