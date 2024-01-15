#ifndef PRESETCONTROLLER_H
#define PRESETCONTROLLER_H

#include "appsettings.h"
#include "WorkState.h"
#include "Button.h"
#include "PresetStorage.h"

class PresetController {
    private:
      PresetStorage storage = PresetStorage();
      Button userButton = Button(BTN_USER);
      Button presetButtons[ACTIVE_PRESETS];
      int pressedButton;

      WorkState returnValue(WorkState state, int button);

    public: 
      PresetController();
      WorkState getState();
      int getPresetValue();
      void setPresetValue(int value);
};

#endif