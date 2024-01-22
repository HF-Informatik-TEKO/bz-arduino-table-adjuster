#include "Arduino.h"
#include "appsettings.h"
#include "PresetStorage.h"

PresetStorage::PresetStorage() {
  user = DEFAULT_USER;

  for (int i = 0; i < ACTIVE_USERS; i++) {
    for (int j = 0; j < ACTIVE_PRESETS; j++) {
      storage[i][j] = PRESETS[i][j];    
    }
  }
}

void PresetStorage::setUser(int userId) {
  user = userId;
}

void PresetStorage::setPreset(int presetId, int presetValue) {
  storage[user][presetId] = presetValue;
}

int PresetStorage::getPreset(int presetId) {
  return storage[user][presetId];
}