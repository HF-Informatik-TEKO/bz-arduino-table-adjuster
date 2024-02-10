#include "HardwareSerial.h"
#include "Arduino.h"
#include "PresetController.h"

PresetController::PresetController() {
  presetButtons[0] = new Button(PIN_BTN_USER);

  for(int i = 0; i < ACTIVE_PRESETS; i++) {
    presetButtons[i + 1] = new Button(PIN_BTN_PRESETS[i]);
  }

  pressedButton = 0;
}

// Handling multiple buttons outside this for-loop leads to bugs.
WorkState PresetController::getState() {
  for (int i = 0; i < ACTIVE_PRESETS + 1; i++) {
    ButtonState state = presetButtons[i]->getState();

    bool isUserButton = i == 0;
    if (isUserButton) {
      if (state == PressedShort) {
        storage->iterateUser(1);
      }
      if (state == PressedLong) {
        // No implementation for user button long pressed.
      }
      continue;
    }

    // Handle preset button.
    if (state == PressedShort) {
      return returnValue(GoToHeight, i);
    }
    if (state == PressedLong) {
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