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
      StatusLight(StatusLightConfig* config);
      void setFreeStatus();
      void setBusyStatus();
      void setErrorStatus();
};

#endif