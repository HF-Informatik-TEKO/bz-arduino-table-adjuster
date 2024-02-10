#ifndef USERSPRESETSDEFAULT_H
#define USERSPRESETSDEFAULT_H

class UsersPresetsDefault {
	public:
    const static int MAX_USERS = 2;
    const static int MAX_PRESETS = 2;

    int defaultUser = 0;
    int defaultPresetValues[MAX_USERS][MAX_PRESETS] = {
      {150, 170},
      {200, 220}
    };

    UsersPresetsDefault() {}
};

#endif
