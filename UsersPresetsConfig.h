#ifndef USERSPRESETSCONFIG_H
#define USERSPRESETSCONFIG_H

class UsersPresetsConfig {
	public:
    int activeUsers = 2;
    int activePresets = 2;
    int pinBtnEmergency = 52;
    int pinBtnUser = 49;
    int pinBtnPresets[5] = { 47, 45 };

    UsersPresetsConfig() {}
};

#endif
