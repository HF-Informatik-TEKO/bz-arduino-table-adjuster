#ifndef CONFIGULTRASONIC_H
#define CONFIGULTRASONIC_H

class ConfigUltrasonic {
	public:
    int trigger = 48;
    int echo = 49;
    int tolerance = 2;

    ConfigUltrasonic() {}
};

#endif
