#include "HardwareSerial.h"
#include "Arduino.h"
#include "PresetController.h"

// Handling multiple buttons outside this for-loop leads to bugs.
WorkState PresetController::getState() {
  for (int i = 0; i < sizeof(buttons) + 1; i++) {
    ButtonState state = buttons[i].getState();

    bool isUserButton = i == 0;
    if (isUserButton) {
      if (state == PressedShort) {
        Serial.println("PresetController::getState: Preset user press.");
        storage->iterateUser(1);
      }
      if (state == PressedLong) {
        // No implementation for user button long pressed.
      }
      continue;
    }

    // Handle preset button.
    if (state == PressedShort) {
      Serial.println("PresetController::getState: Preset short press.");
      return returnValue(GoToHeight, i);
    }
    if (state == PressedLong) {
      Serial.println("PresetController::getState: Preset long press.");
      return returnValue(SetHeight, i);
    }
  }

  return NoWorkState;
}

WorkState PresetController::returnValue(WorkState state, int button) {
  pressedButton = button - 1;
  return state;
}

int PresetController::getPresetValue() {
  return storage->getPreset(pressedButton);
}

void PresetController::setPresetValue(int value) {
  storage->setPreset(pressedButton, value);
}