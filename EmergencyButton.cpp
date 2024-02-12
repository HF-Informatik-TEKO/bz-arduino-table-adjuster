#include "Arduino.h"
#include "EmergencyButton.h"


EmergencyButton::EmergencyButton(int pin) {
    this->pin = pin;
    this->emergencyLastState = 0;
    this->isActive = false;
}
bool EmergencyButton::isEmergency() {
  int emergencyState = digitalRead(pin);
  
  if (emergencyLastState != emergencyState) {
    emergencyLastState = emergencyState;
    if (emergencyState == HIGH) {
      isActive = !isActive;
      Serial.println("EmergencyButton::isEmergency Toggle isEmergency");
    }
  }

  return isActive;
}