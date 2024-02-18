#include "Arduino.h"
#include "TableAdjuster.h"

TableAdjuster::TableAdjuster(
  ConfigUsersPresets* usersPresetConfig,
  ConfigDuration* durationsConfig,
  PresetController* preset, 
  TableController* table, 
  StatusLight* status
  ) 
{
  Serial.println("TableAdjuster::setup Start Setup");
  this->loopDurationMs = durationsConfig->loopDurationMs;
  this->timeoutDurationMs = durationsConfig->timeoutDurationMs;
  this->preset = preset;
  this->table = table;
  this->status = status;
  timeoutCounter = 0;
  emergencyButton = new EmergencyButton(usersPresetConfig->pinBtnEmergency);

  status->setErrorStatus();
  delay(800);
  status->setBusyStatus();
  delay(800);
  status->setFreeStatus();
  Serial.println("TableAdjuster::setup Finish Setup");
}

void TableAdjuster::cycleDelay() {
  delay(loopDurationMs);
}

void TableAdjuster::cycle() {
  if (emergencyButton->isEmergency()) {
    if (emergencyButton->hasStateChanged()) {
      activateEmergencyStatus();
    }
    return;
  }
  
  if (state == NoWorkState) {
    changeState(preset->getState());
  } 

  if (state == GoToHeight) {
    status->setBusyStatus();
    moveTable();
  } else if (state == SetHeight) {
    status->setBusyStatus();
    setHeight();
  } else {
    status->setFreeStatus();
  }

  if (timeoutCounter >= timeoutDurationMs) {
    timeout("TableAdjuster");
  }

  timeoutCounter += loopDurationMs;
}

void TableAdjuster::activateEmergencyStatus() {
  status->setErrorStatus();
  table->stop();
  changeState(NoWorkState);
}

void TableAdjuster::moveTable() {
  if (timeoutCounter >= timeoutDurationMs) {
    table->stop();
    timeout("TableAdjuster::moveTable");
    return; 
  } 

  int presetHeight = preset->getPresetValue();
  MoveDirection direction = table->goToPosition(presetHeight);
  if (direction == None) {
    Serial.println("TableAdjuster::moveTable reached correct position.");
    resetState();
  }
}

void TableAdjuster::setHeight() {
  int currentPos = table->getCurrentPosition();
  preset->setPresetValue(currentPos);
  Serial.print("TableAdjuster::setHeight set height to ");
  Serial.println(currentPos);
  resetState();
}

void TableAdjuster::timeout(String className) {
  status->setErrorStatus();
  resetState();
  Serial.println("!!! TIMEOUT !!!");
  Serial.print(className);
  Serial.print(" timed out. took more than (ms) ");
  Serial.println(timeoutDurationMs);
  delay(500);
}

void TableAdjuster::resetState() {
  state = NoWorkState;
  timeoutCounter = 0;
}

void TableAdjuster::changeState(WorkState newState) {
  state = newState;
  timeoutCounter = 0;
}