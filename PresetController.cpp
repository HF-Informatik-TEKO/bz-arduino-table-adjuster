#include "Arduino.h"
#include "PresetController.h"

PresetController::PresetController() {
  for(int i = 0; i < ACTIVE_PRESETS; i++) {
    presetButtons[i] = (BTN_PRESETS[i]);
  }

  pressedButton = 0;
}

WorkState PresetController::getState() {
  for (int i = 0; i < ACTIVE_PRESETS; i++) {
    ButtonState state = presetButtons[i].getState();

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
  pressedButton = button;
  return state;
}

int PresetController::getPresetValue() {
  return storage.getPreset(pressedButton);
}

void PresetController::setPresetValue(int value) {
  storage.setPreset(pressedButton, value);
}