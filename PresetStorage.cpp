#include "Arduino.h"
#include "PresetStorage.h"

void PresetStorage::setUser(int userId) {
  selectedUser = userId % maxUsers;
}

void PresetStorage::iterateUser(int increment) {
  selectedUser += increment;
  selectedUser %= maxUsers;
  Serial.print("PresetStorage: active user is user_");
  Serial.println(selectedUser);

  Serial.print("PresetStorage: user values: ");
  Serial.print(storage[selectedUser][0]);
  Serial.print(" - ");
  Serial.println(storage[selectedUser][1]);
}

void PresetStorage::setPreset(int presetId, int presetValue) {
  storage[selectedUser][presetId] = presetValue;
}

int PresetStorage::getPreset(int presetId) {
  return storage[selectedUser][presetId];
}