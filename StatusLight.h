#ifndef STATUSLIGHT_H
#define STATUSLIGHT_H

#include "LED.h"
#include "StatusLightConfig.h"

class StatusLight {
    private:
      LED* green;
      LED* yellow;
      LED* red;

    public: 
      StatusLight(StatusLightConfig* config) {
        red = new LED(config->red);
        yellow = new LED(config->yellow);
        green = new LED(config->green);
      }
      void setFreeStatus();
      void setBusyStatus();
      void setErrorStatus();
};

#endif