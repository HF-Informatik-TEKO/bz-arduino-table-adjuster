#ifndef EMERGENCYBUTTON_H
#define EMERGENCYBUTTON_H

#include "WorkState.h"

class EmergencyButton {
  private:
    int pin;
    int emergencyLastState;
    bool isActive;
    bool hasChanged;

  public:
    EmergencyButton(int pin);
    bool isEmergency();
    bool hasStateChanged();
};

#endif