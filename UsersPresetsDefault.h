#ifndef USERSPRESETSDEFAULT_H
#define USERSPRESETSDEFAULT_H

class UsersPresetsDefault {
	public:
    int defaultUser = 0;
    int defaultPresetValues[5][5] = {
      {10, 20},
      {15, 25}
    };

    UsersPresetsDefault() {}
};

#endif
