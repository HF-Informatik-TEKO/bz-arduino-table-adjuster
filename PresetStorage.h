#ifndef PRESETSTORAGE_H
#define PRESETSTORAGE_H

#include "ConfigUsersPresets.h"
#include "ConfigUsersPresetsDefault.h"

class PresetStorage {
  private:
    int maxUsers;
    int selectedUser;
    int** storage;

  public:
    PresetStorage(ConfigUsersPresets* users, ConfigUsersPresetsDefault* userDefaults);    
    void setUser(int user);
    void iterateUser(int increment);
    void setPreset(int presetId, int presetValue);
    int getPreset(int presetId);
};

#endif