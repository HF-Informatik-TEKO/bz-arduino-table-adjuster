#ifndef BUILDER_H
#define BUILDER_H

#include "TableAdjuster.h"
#include "ServoConfig.h"
#include "StatusLightConfig.h"
#include "UltrasonicConfig.h"
#include "UsersPresetsConfig.h"
#include "DurationsConfig.h"
#include "UsersPresetsDefault.h"

class Builder {
  private:
  // Constants
    static const int MAX_PRESETS = 2;
    static const int MAXUSERS = 2;

    UsersPresetsConfig* usersPresetConfig = new UsersPresetsConfig();
    DurationsConfig* durationsConfig = new DurationsConfig();
    UsersPresetsDefault* userPresetDefault = new UsersPresetsDefault();
    UltrasonicConfig* ultrasonicConfig = new UltrasonicConfig();
    StatusLightConfig* statusConfig = new StatusLightConfig();
    ServoConfig* servoConfig = new ServoConfig();

  public:
    Builder() {}

    TableAdjuster& build() {
      PresetController* pc = new PresetController(usersPresetConfig, userPresetDefault, durationsConfig);
      TableController* tc = new TableController(ultrasonicConfig, servoConfig);
      StatusLight* status = new StatusLight(statusConfig);

      TableAdjuster* ta = new TableAdjuster(pc, tc, status);
      return *ta;
    }

#pragma region UsersPresetsConfig
    Builder& setPinBtnPresets(int pos, int pin) {
      usersPresetConfig->pinBtnPresets[pos] = pin;
      return *this;
    }

    Builder& setPinBtnUser(int pin) {
      usersPresetConfig->pinBtnUser = pin;
      return *this;
    }

    Builder& setActiveUsers(int number) {
      usersPresetConfig->activeUsers = number;
      return *this;
    }

    Builder& setActivePresets(int number) {
      usersPresetConfig->activePresets = number;
      return *this;
    }
#pragma endregion

#pragma region DurationsConfig
    Builder& setLoopDurationMs(int duration) {
      durationsConfig->loopDurationMs = duration;
      return *this;
    }
    Builder& setTimeoutDurationMs(int duration) {
      durationsConfig->timeoutDurationMs = duration;
      return *this;
    }

    Builder& setButtonLongPressMs(int duration) {
      durationsConfig->buttonLongPressMs = duration;
      return *this;
    }
#pragma endregion

#pragma region DefaultsConfig
    Builder& setDefaultUser(int number) {
      userPresetDefault->defaultUser = number;
      return *this;
    }

    Builder& setDefaultValues(int pos, int values[2]) {
      userPresetDefault->defaultPresetValues[pos][0] = values[0];
      userPresetDefault->defaultPresetValues[pos][1] = values[1];
      return *this;
    }
#pragma endregion

#pragma region Ultrasonic
    Builder& setPinUltrasonicTrigger(int pin) {
      ultrasonicConfig->trigger = pin;
      return *this;
    }

    Builder& setPinUltrasonicEcho(int pin) {
      ultrasonicConfig->echo = pin;
      return *this;
    }

    Builder& setHeightTolerance(int tolerance) {
      ultrasonicConfig->tolerance = tolerance;
      return *this;
    }
#pragma endregion

#pragma region StatusLight
    Builder& setPinStatusLedRed(int pin) {
      statusConfig->red = pin;
      return *this;
    }

    Builder& setPinStatusLedGreen(int pin) {
      statusConfig->green = pin;
      return *this;
    }

    Builder& setPinStatusLedYellow(int pin) {
      statusConfig->yellow = pin;
      return *this;
    }
#pragma endregion

#pragma region Servo
    Builder& setPinServo(int pin) {
      servoConfig->pin = pin;
      return *this;
    }
#pragma endregion
};

#endif