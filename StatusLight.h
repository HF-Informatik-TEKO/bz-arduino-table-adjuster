#ifndef STATUSLIGHT_H
#define STATUSLIGHT_H

#include "appsettings.h"
#include "LED.h"

class StatusLight {
    private:
      LED green = LED(STATUS_LED_GREEN);
      LED yellow = LED(STATUS_LED_YELLOW);
      LED red = LED(STATUS_LED_RED);

    public: 
      void setFreeStatus();
      void setBusyStatus();
      void setErrorStatus();
};

#endif