#include "Arduino.h"
#include "TableAdjuster.h"

TableAdjuster::TableAdjuster() {
  preset = PresetController();
  table = TableController();
  status = StatusLight();
  resetState();
}

void TableAdjuster::cycle() {
  if (state == NoWorkState) {
    WorkState currentState = preset.getState();
    changeState(currentState);
    // Green LED.
    status.setFreeStatus();
  } 

  if (state == GoToHeight) {
    // Yellow LED.
    status.setBusyStatus();
    moveTable();
  } else if (state == SetHeight) {
    // Yellow LED.
    status.setBusyStatus();
    setHeight();
  }

  if (timeoutCounter >= (TIMEOUT_DURATION_MS)) {
    timeout("table-adjuster");
  }

  timeoutCounter += LOOP_DURATION_MS;
}

void TableAdjuster::moveTable() {
  if (timeoutCounter >= TIMEOUT_DURATION_MS) {
    table.stop();
    timeout("table-adjuster::GoToHeight");
  } else {
    int presetHeight = preset.getPresetValue();
    MoveDirection direction = table.goToPosition(presetHeight);
    if (direction == None) {
      Serial.println("table-adjuster::GoToHeight reached correct position.");
      resetState();
    }
  }
}

void TableAdjuster::setHeight() {
  int currentPos = table.getCurrentPosition();
  preset.setPresetValue(currentPos);
  Serial.print("table-adjuster::SetHeight set height to ");
  Serial.println(currentPos);
  resetState();
}


void TableAdjuster::timeout(String className) {
  // Red LED.
  resetState();
  Serial.println("!!! TIMEOUT !!!");
  Serial.print(className);
  Serial.print(" timed out. took more than (ms) ");
  Serial.println(TIMEOUT_DURATION_MS);
}

void TableAdjuster::resetState() {
  state = NoWorkState;
  timeoutCounter = 0;
}

void TableAdjuster::changeState(WorkState newState) {
  state = newState;
  timeoutCounter = 0;
}