#ifndef CONFIGULTRASONIC_H
#define CONFIGULTRASONIC_H

class ConfigUltrasonic {
	public:
    int trigger = 5;
    int echo = 6;
    int tolerance = 2;

    ConfigUltrasonic() {}
};

#endif
