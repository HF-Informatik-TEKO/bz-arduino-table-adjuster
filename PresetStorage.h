class PresetStorage {
  private:
    int storage[2][2] = { {500, 800}, {500, 800} };
    int user;

  public:
    void setUser(int user);
    void setPreset(int presetId, int presetValue);
    int getPreset(int presetId);
};