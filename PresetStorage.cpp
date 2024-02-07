#include "Arduino.h"
#include "appsettings.h"
#include "PresetStorage.h"

PresetStorage::PresetStorage() {
  setUser(DEFAULT_USER);

  for (int i = 0; i < ACTIVE_USERS; i++) {
    for (int j = 0; j < ACTIVE_PRESETS; j++) {
      storage[i][j] = DEFAULT_PRESET_VLAUES[i][j];    
    }
  }
}

void PresetStorage::setUser(int userId) {
  user = userId % ACTIVE_USERS;
}

void PresetStorage::iterateUser(int increment) {
  user = user + increment;
  user = user % ACTIVE_USERS;
  Serial.print("PresetSTorage: active user is user_");
  Serial.println(user);

  Serial.print("PresetSTorage: user values: ");
  Serial.print(storage[user][0]);
  Serial.print(" - ");
  Serial.println(storage[user][1]);
}

void PresetStorage::setPreset(int presetId, int presetValue) {
  storage[user][presetId] = presetValue;
}

int PresetStorage::getPreset(int presetId) {
  return storage[user][presetId];
}