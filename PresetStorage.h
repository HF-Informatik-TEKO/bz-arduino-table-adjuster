class PresetStorage {
  private:
    int storage[2][2];
    int user;

  public:
    PresetStorage();
    void setUser(int user);
    void setPreset(int presetId, int presetValue);
    int getPreset(int presetId);
};