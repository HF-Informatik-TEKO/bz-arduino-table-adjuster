#ifndef CONFIGUSERSPRESETS_H
#define CONFIGUSERSPRESETS_H

class ConfigUsersPresets {
	public:
    int activeUsers = 2;
    int activePresets = 2;
    int pinBtnEmergency = 52;
    int pinBtnUser = 53;
    int pinBtnPresets[5] = { 51, 50 };

    ConfigUsersPresets() {}
};

#endif
