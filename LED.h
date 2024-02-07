#ifndef LED_H
#define LED_H
class LED {
	private:
		int pin;

	public:
		LED(int pin); // Constructor
		void on();
		void off();
    void blink(int durationMS);
};

#endif
