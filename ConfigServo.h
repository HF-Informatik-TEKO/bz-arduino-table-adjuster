#ifndef CONFIGSERVO_H
#define CONFIGSERVO_H

#include "ButtonState.h"

class ConfigServo {
  public:
    int pin = 44;
    int upPos = 120;
    int stopPos = 90;
    int downPos = 60;

    ConfigServo() {}
};

#endif