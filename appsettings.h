#ifndef APPSETTINGS_H
#define APPSETTINGS_H

// Buttons
const int BTN_PRESETS[] = { 47, 45 };
const int BTN_USER = 49;
const int SWITCH_LONG_PUSH_MS = 1000;

// Global
const int LOOP_DURATION_MS = 50;
const int ACTIVE_USERS = 2;
const int ACTIVE_PRESETS = 2;

// Default Values
const int DEFAULT_USER = 0;
const int PRESETS[2][2] = {
  {100, 120},
  {200, 220}
} ;

#endif