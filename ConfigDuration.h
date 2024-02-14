#ifndef CONFIGDURATION_H
#define CONFIGDURATION_H

class ConfigDuration {
	private:
		int pin;

	public:
    int loopDurationMs = 50;
    int timeoutDurationMs = 3000;
    int buttonLongPressMs = 1000;

		ConfigDuration() {}
};

#endif
