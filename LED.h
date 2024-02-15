#ifndef LED_H
#define LED_H

class LED {
	private:
		int pin;

	public:
		LED(int pin);
		void on();
		void off();
    	void blink(int times, int durationMS);
};

#endif
