#include "Arduino.h"
#include "LED.h"

LED::LED(int pin) {
	this->pin = pin;
  pinMode(pin, OUTPUT);
}

void LED::on() {
	digitalWrite(pin, HIGH);
}

void LED::off() {
	digitalWrite(pin, LOW);
}

void LED::blink(int durationMS) {
    on();
    delay(durationMS);
    off();
    delay(durationMS);
    on();
    delay(durationMS);
    off();
}