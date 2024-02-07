#ifndef APPSETTINGS_H
#define APPSETTINGS_H

// Buttons
// Peset 1, Preset 2, ...
const int BTN_PRESETS[] = { 47, 45 };
const int BTN_USER = 49;

// Distance
const int ULTRASONIC_TRIGGER = 5;
const int ULTRASONIC_ECHO = 6;
const int HEIGHT_TOLERANCE = 2;

// Times
const int LOOP_DURATION_MS = 50;
const int TIMEOUT_DURATION_MS = 3000;
const int BUTTON_LONG_PRESS_MS = 1000;

// Default Values
const int ACTIVE_USERS = 2;
const int ACTIVE_PRESETS = 2;
const int DEFAULT_USER = 0;
const int DEFAULT_PRESET_VLAUES[2][2] = {
  {150, 170},
  {200, 220}
};

#endif
