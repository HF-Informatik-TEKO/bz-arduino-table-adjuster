#include "PresetStorage.h"

void PresetStorage::setUser(int userId) {
  this->user = userId;
}

void PresetStorage::setPreset(int presetId, int presetValue) {
  storage[user][presetId] = presetValue;
}

int PresetStorage::getPreset(int presetId) {
  return storage[user][presetId];
}