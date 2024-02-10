#ifndef APPSETTINGS_H
#define APPSETTINGS_H

// Buttons
// Pesets and Users
const int PIN_BTN_PRESETS[] = { 47, 45 };
const int PIN_BTN_USER = 49;
const int LOOP_DURATION_MS = 50;
const int TIMEOUT_DURATION_MS = 3000;
const int BUTTON_LONG_PRESS_MS = 1000;

const int ACTIVE_USERS = 2;
const int ACTIVE_PRESETS = 2;
const int DEFAULT_USER = 0;
const int DEFAULT_PRESET_VLAUES[2][2] = {
  {150, 170},
  {200, 220}
};

// Other Components
// Distance
const int PIN_ULTRASONIC_TRIGGER = 5;
const int PIN_ULTRASONIC_ECHO = 6;
const int HEIGHT_TOLERANCE = 2;

// Status Light
const int PIN_STATUS_LED_RED = 52;
const int PIN_STATUS_LED_GREEN = 51;
const int PIN_STATUS_LED_YELLOW = 50;

// Servo
const int PIN_SERVO = 22;

#endif
