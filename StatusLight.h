#ifndef STATUSLIGHT_H
#define STATUSLIGHT_H

#include "appsettings.h"
#include "LED.h"
// #include "MyLed.h"

class StatusLight {
    private:
      LED* green = new LED(PIN_STATUS_LED_GREEN);
      LED* yellow = new LED(PIN_STATUS_LED_YELLOW);
      LED* red = new LED(PIN_STATUS_LED_RED);
      // MyLed green = MyLed(STATUS_LED_GREEN);
      // MyLed yellow = MyLed(STATUS_LED_YELLOW);
      // MyLed red = MyLed(STATUS_LED_RED);

    public: 
      void setFreeStatus();
      void setBusyStatus();
      void setErrorStatus();
};

#endif