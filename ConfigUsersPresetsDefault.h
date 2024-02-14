#ifndef CONFIGUSERSPRESETSDEFAULT_H
#define CONFIGUSERSPRESETSDEFAULT_H

class ConfigUsersPresetsDefault {
	public:
    int defaultUser = 0;
    int defaultPresetValues[5][5] = {
      {10, 20},
      {15, 25}
    };

    ConfigUsersPresetsDefault() {}
};

#endif
