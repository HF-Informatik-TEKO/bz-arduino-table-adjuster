#ifndef PRESETSTORAGE_H
#define PRESETSTORAGE_H

class PresetStorage {
  private:
    int storage[ACTIVE_USERS][ACTIVE_PRESETS];
    int user;

  public:
    PresetStorage();
    void setUser(int user);
    void iterateUser(int increment);
    void setPreset(int presetId, int presetValue);
    int getPreset(int presetId);
};

#endif