#ifndef USERSPRESETSCONFIG_H
#define USERSPRESETSCONFIG_H

class UsersPresetsConfig {
	public:
    static const int MAX_PRESETS = 2;

    UsersPresetsConfig() {}

    int activeUsers = 2;
    int activePresets = 2;
    int pinBtnUser = 49;
    int pinBtnPresets[MAX_PRESETS] = { 47, 45 };
};

#endif
