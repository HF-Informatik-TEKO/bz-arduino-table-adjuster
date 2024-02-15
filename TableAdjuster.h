#ifndef TABLEADJUSTER_H
#define TABLEADJUSTER_H

#include "PresetController.h"
#include "TableController.h"
#include "Statuslight.h"
#include "WorkState.h"
#include "EmergencyButton.h"

#include "ConfigServo.h"
#include "ConfigStatusLight.h"
#include "ConfigUltrasonic.h"
#include "ConfigUsersPresets.h"
#include "ConfigDuration.h"
#include "ConfigUsersPresetsDefault.h"

class TableAdjuster {
  private:
    PresetController* preset;
    TableController* table;
    StatusLight* status;
    EmergencyButton* emergencyButton;
    WorkState state;
    int timeoutCounter;
    int timeoutDurationMs;
    int loopDurationMs;
    bool isEmergency;

    void moveTable();
    void setHeight();
    void resetState();
    void changeState(WorkState newState);
    void timeout(String className);
    void activateEmergencyStatus();

  public:
    TableAdjuster(
      ConfigUsersPresets* usersPresetConfig,
      ConfigDuration* durationsConfig, 
      PresetController* preset, 
      TableController* table, 
      StatusLight* status
    );
    void cycleDelay();
    void cycle();
};

#endif