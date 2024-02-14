#include "PresetController.h"
#include "Arduino.h"

PresetController::PresetController(
  ConfigUsersPresets* users, 
  ConfigUsersPresetsDefault* userDefaults, 
  ConfigDuration* durationsConfig
  ) 
{
  storage = new PresetStorage(users, userDefaults);
  pressedButton = 0;

  int amountOfButtons = users->activePresets + 1;
  numberOfButtons = amountOfButtons;
  buttons = new Button*[amountOfButtons];
  buttons[0] = new Button(users->pinBtnUser, durationsConfig);
  for(int i = 0; i < users->activePresets; i++) {
    buttons[i + 1] = new Button(users->pinBtnPresets[i], durationsConfig);
  }
}

// Handling multiple buttons outside this for-loop leads to bugs.
WorkState PresetController::getState() {
  for (int i = 0; i < numberOfButtons; i++) {
    ButtonState state = buttons[i]->getState();

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