#include "Arduino.h"
#include "TableAdjuster.h"

TableAdjuster::TableAdjuster(
  UsersPresetsConfig* usersPresetConfig,
  DurationsConfig* durationsConfig,
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
  this->timeoutCounter = 0;
  this->emergencyButton = new EmergencyButton(usersPresetConfig->pinBtnEmergency);

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
    if (!isEmergency) {
      activateEmergencyStatus();
    }
    return;
  }
  
  isEmergency = false;

  if (state == NoWorkState) {
    WorkState currentState = preset->getState();
    changeState(currentState);
    status->setFreeStatus();
  } 

  if (state == GoToHeight) {
    status->setBusyStatus();
    moveTable();
  } else if (state == SetHeight) {
    status->setBusyStatus();
    setHeight();
  }

  if (timeoutCounter >= timeoutDurationMs) {
    timeout("TableAdjuster");
  }

  timeoutCounter += loopDurationMs;
}

void TableAdjuster::activateEmergencyStatus() {
  isEmergency = true;
  status->setErrorStatus();
  table->stop();
  changeState(NoWorkState);
}

void TableAdjuster::moveTable() {
  if (timeoutCounter >= timeoutDurationMs) {
    table->stop();
    timeout("TableAdjuster::moveTable");
  } else {
    int presetHeight = preset->getPresetValue();
    MoveDirection direction = table->goToPosition(presetHeight);
    if (direction == None) {
      Serial.println("TableAdjuster::moveTable reached correct position.");
      resetState();
    }
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