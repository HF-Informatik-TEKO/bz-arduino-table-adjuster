#ifndef CONFIGUSERSPRESETS_H
#define CONFIGUSERSPRESETS_H

class ConfigUsersPresets {
	public:
    int activeUsers = 2;
    int activePresets = 2;
    int pinBtnEmergency = 52;
    int pinBtnUser = 49;
    int pinBtnPresets[5] = { 47, 45 };

    ConfigUsersPresets() {}
};

#endif
