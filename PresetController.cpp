#include "PresetController.h"

PresetController::PresetController(
  UsersPresetsConfig* users, 
  UsersPresetsDefault* userDefaults, 
  DurationsConfig* durationsConfig) 
{
  storage = new PresetStorage(users, userDefaults);
  pressedButton = 0;

  int amountOfButtons = users->activePresets + 1;
  buttons = new Button[amountOfButtons];
  buttons[0] = Button(users->pinBtnUser, durationsConfig);
  for(int i = 0; i < users->activePresets; i++) {
    buttons[i + 1] = Button(users->pinBtnPresets[i], durationsConfig);
  }
}

// Handling multiple buttons outside this for-loop leads to bugs.
WorkState PresetController::getState() {
  for (int i = 0; i < sizeof(buttons) + 1; i++) {
    ButtonState state = buttons[i].getState();

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