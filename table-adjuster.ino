#include "appsettings.h"
#include "PresetController.h"
#include "TableController.h"

PresetController preset;
TableController table;
WorkState state;
WorkState lastState;

int timeoutCounter = 0;


void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.println("Program Start");
  preset = PresetController();
  table = TableController();
  // TODO: Falsify appsettings values. e.g. more active presets than default values. etc.
}

void loop() {
  if (state == NoWorkState) {
    WorkState currentState = preset.getState();
    changeState(currentState);
  } 

  if (state == GoToHeight) {


    if (timeoutCounter >= TIMEOUT_DURATION_MS) {
      table.stop();
      timeout("table-adjuster::GoToHeight");
    } else {
      int presetHeight = preset.getPresetValue();
      MoveDirection direction = table.goToPosition(presetHeight);
      if (direction == None) {
        Serial.print("table-adjuster::GoToHeight reached correct position.");
        resetState();
      }
    }


  } else if (state == SetHeight) {


    if (timeoutCounter == 0) {

      int currentPos = table.getCurrentPosition();
      preset.setPresetValue(currentPos);
      Serial.print("table-adjuster::SetHeight set height to ");
      Serial.println(currentPos);
      resetState();
    }


  }

  if (timeoutCounter >= (TIMEOUT_DURATION_MS)) {
    timeout("table-adjuster");
  }

  timeoutCounter += LOOP_DURATION_MS;
  delay(LOOP_DURATION_MS);
}

void timeout(String className) {
  resetState();
  Serial.println("!!! TIMEOUT !!!");
  Serial.print(className);
  Serial.print(" timed out. took more than (ms) ");
  Serial.println(TIMEOUT_DURATION_MS);
}

void resetState() {
  state = NoWorkState;
  timeoutCounter = 0;
}

void changeState(WorkState newState) {
  lastState = state;
  state = newState;
  timeoutCounter = 0;
}
