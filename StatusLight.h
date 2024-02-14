#ifndef STATUSLIGHT_H
#define STATUSLIGHT_H

#include "LED.h"

#include "ConfigStatusLight.h"

class StatusLight {
    private:
      LED* green;
      LED* yellow;
      LED* red;

    public: 
      StatusLight(ConfigStatusLight* config);
      void setFreeStatus();
      void setBusyStatus();
      void setErrorStatus();
};

#endif