#ifndef DURATIONSCONFIG_h
#define DURATIONSCONFIG_h

class DurationsConfig {
	private:
		int pin;

	public:
    int loopDurationMs = 50;
    int timeoutDurationMs = 3000;
    int buttonLongPressMs = 1000;

		DurationsConfig() {}
};

#endif
