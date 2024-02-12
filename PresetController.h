#ifndef PRESETCONTROLLER_H
#define PRESETCONTROLLER_H

#include "WorkState.h"
#include "Button.h"
#include "PresetStorage.h"

#include "UsersPresetsConfig.h"
#include "UsersPresetsDefault.h"
#include "DurationsConfig.h"


class PresetController {
    private:
      PresetStorage* storage;
      Button** buttons;
      int pressedButton;
      int numberOfButtons;

      WorkState returnValue(WorkState state, int button);

    public: 
      PresetController(UsersPresetsConfig* users, UsersPresetsDefault* userDefaults, DurationsConfig* durationsConfig);
      WorkState getState();
      int getPresetValue();
      void setPresetValue(int value);
};

#endif