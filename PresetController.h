#ifndef PRESETCONTROLLER_H
#define PRESETCONTROLLER_H

#include "Arduino.h"
#include "WorkState.h"
#include "Button.h"
#include "PresetStorage.h"
#include "UsersPresetsConfig.h"
#include "UsersPresetsDefault.h"
#include "DurationsConfig.h"


class PresetController {
    private:
      // + 1 for user button.
      PresetStorage* storage;
      Button* buttons;
      int pressedButton;

      WorkState returnValue(WorkState state, int button);

    public: 
      PresetController(UsersPresetsConfig* users, UsersPresetsDefault* userDefaults, DurationsConfig* durationsConfig) {
        storage = new PresetStorage(users, userDefaults);
        pressedButton = 0;

        int amountOfButtons = users->activePresets + 1;
        buttons = new Button[amountOfButtons];
        buttons[0] = Button(users->pinBtnUser, durationsConfig);
        for(int i = 0; i < users->activePresets; i++) {
          // Serial.print("PresetController::Constructor: added button ");
          // Serial.println(users->pinBtnPresets[i]);
          buttons[i + 1] = Button(users->pinBtnPresets[i], durationsConfig);
        }
      }

      WorkState getState();
      int getPresetValue();
      void setPresetValue(int value);
};

#endif