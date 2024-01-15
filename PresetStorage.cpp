#include "appsettings.h"
#include "PresetStorage.h"

PresetStorage::PresetStorage(int none) {
  storage[0][0] = PRESET_1[0];
  storage[0][1] = PRESET_1[1];

  storage[1][0] = PRESET_2[0];
  storage[1][1] = PRESET_2[1];
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

