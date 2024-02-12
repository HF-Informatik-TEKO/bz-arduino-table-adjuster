#ifndef EMERGENCYBUTTON_H
#define EMERGENCYBUTTON_H


class EmergencyButton {
  private:
    int pin;
    int emergencyLastState;
    bool isActive;

  public:
    EmergencyButton(int pin);
    bool isEmergency();
};

#endif