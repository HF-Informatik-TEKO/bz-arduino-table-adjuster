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
    PresetStorage(UsersPresetsConfig* users, UsersPresetsDefault* userDefaults) {
      maxUsers = users->activeUsers;
      storage = new int*[maxUsers];
      setUser(userDefaults->defaultUser);

      for (int i = 0; i < maxUsers; i++) {
        storage[i] = new int[users->activePresets];
        for (int j = 0; j < users->activePresets; j++) {
          storage[i][j] = userDefaults->defaultPresetValues[i][j];    
        }
      }
    }
    
    void setUser(int user);
    void iterateUser(int increment);
    void setPreset(int presetId, int presetValue);
    int getPreset(int presetId);
};

#endif