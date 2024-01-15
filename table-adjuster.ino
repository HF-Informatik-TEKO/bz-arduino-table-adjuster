#include "appsettings.h"
#include "LED.h"
#include "Switch.h"

LED led(13);
Switch preset1(47, SWITCH_LONG_PUSH_MS, LOOP_DURATION_MS);
Switch preset2(45, SWITCH_LONG_PUSH_MS, LOOP_DURATION_MS);

SwitchState lastPreste1State = None;

void setup() {
  Serial.begin(9600);
}

void loop() {

  SwitchState state = preset1.checkSwitch();
  
  if (state == lastPreste1State) {
    delay(LOOP_DURATION_MS);
    return;
  }

  Serial.print(state);
  Serial.print("\n");

  if (state == None || state == NoPush || state == lastPreste1State) {
    led.off();
  } else if (state == LongPush) {
    led.on();
  } else if (state == ShortPush) {
    led.blink(300);
  }

  lastPreste1State = state;
  delay(LOOP_DURATION_MS);
}
