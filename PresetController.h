#ifndef PRESETCONTROLLER_H
#define PRESETCONTROLLER_H

#include "appsettings.h"
#include "WorkState.h"
#include "Button.h"
#include "PresetStorage.h"

class PresetController {
    private:
      // + 1 for user button.
      PresetStorage* storage = new PresetStorage();
      Button* userButton = new Button(PIN_BTN_USER);
      Button* presetButtons[ACTIVE_PRESETS + 1];
      int amountOfButtons = ACTIVE_PRESETS + 1;
      int pressedButton;

      WorkState returnValue(WorkState state, int button);

    public: 
      PresetController();
      void loopUserIfNeeded();
      WorkState getState();
      int getPresetValue();
      void setPresetValue(int value);
};

#endif