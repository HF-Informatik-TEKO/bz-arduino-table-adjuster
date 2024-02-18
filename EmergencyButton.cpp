#include "Arduino.h"
#include "EmergencyButton.h"

EmergencyButton::EmergencyButton(int pin) {
    this->pin = pin;
    emergencyLastState = LOW;
    isActive = false;
    hasChanged = false;
}

bool EmergencyButton::isEmergency() {
  hasChanged = false;
  int emergencyState = digitalRead(pin);
  
  bool hasStateChanged = emergencyLastState != emergencyState;
  if (hasStateChanged) {
    emergencyLastState = emergencyState;

    if (emergencyState == HIGH) {
      hasChanged = true;
      isActive = !isActive;
      Serial.println("EmergencyButton::isEmergency Toggle isEmergency");
    }
  }

  return isActive;
}

bool EmergencyButton::hasStateChanged() {
  return hasChanged;
}