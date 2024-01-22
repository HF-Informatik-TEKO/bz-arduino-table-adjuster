#include "appsettings.h"
#include "PresetController.h"
#include "TableController.h"

PresetController preset;
TableController table;
WorkState state;

int timeoutCounter = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Program Start");
  preset = PresetController();
  table = TableController();
  // TODO: Falsify appsettings values. e.g. more active presets than default values. etc.
}

void loop() {
  if (state == NoWorkState) {
    WorkState currentState = preset.getState();
    state = currentState;
    timeoutCounter = 0;
  } else if (state == GoToHeight) {
    MoveDirection direction = None;

    if (timeoutCounter >= TIMEOUT_DURATION_MS) {
      direction = table.stop();
      timeout("table-adjuster::GoToHeight");
      // Serial.print("table-adjuster::GoToHeight timed out. took more than (ms) ");
      // Serial.println(TIMEOUT_DURATION_MS);
    } else {
      int presetHeight = preset.getPresetValue();
      direction = table.goToPosition(presetHeight);
      if (direction == None) {
        Serial.print("table-adjuster::GoToHeight reached correct position.");
        state = NoWorkState;
      }
    }

  } else if (state == SetHeight) {
    int currentPos = table.getCurrentPosition();
    // Serial.print(currentPos);
    preset.setPresetValue(currentPos);
  }

  if (timeoutCounter >= (TIMEOUT_DURATION_MS)) {
    timeout("table-adjuster");
    // state = NoWorkState;
    // Serial.println("!!! TIMEOUT !!!");
    // Serial.print("table-adjuster timed out. took more than (ms) ");
    // Serial.println(TIMEOUT_DURATION_MS);
  }

  timeoutCounter += LOOP_DURATION_MS;
  delay(LOOP_DURATION_MS);
}

void timeout(String className) {
    state = NoWorkState;
    timeoutCounter = 0;
    Serial.println("!!! TIMEOUT !!!");
    Serial.print(className);
    Serial.print(" timed out. took more than (ms) ");
    Serial.println(TIMEOUT_DURATION_MS);
}
