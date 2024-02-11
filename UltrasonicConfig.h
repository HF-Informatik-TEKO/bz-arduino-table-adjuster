#ifndef ULTRASONICCONFIG_H
#define ULTRASONICCONFIG_H

class UltrasonicConfig {
	public:
    int trigger = 5;
    int echo = 6;
    int tolerance = 2;

    UltrasonicConfig() {}
};

#endif
