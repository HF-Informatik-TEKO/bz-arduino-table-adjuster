#ifndef PRESETSTORAGE_H
#define PRESETSTORAGE_H

#include "UsersPresetsConfig.h"
#include "UsersPresetsDefault.h"

class PresetStorage {
  private:
    int maxUsers;
    int selectedUser;
    int** storage;

  public:
    PresetStorage(UsersPresetsConfig* users, UsersPresetsDefault* userDefaults);    
    void setUser(int user);
    void iterateUser(int increment);
    void setPreset(int presetId, int presetValue);
    int getPreset(int presetId);
};

#endif