#include "appsettings.h"
#include "Button.h"
#include "PresetStorage.h"

Button btn(47);
PresetStorage store(1);

void setup() {
  Serial.begin(9600);
  store.setUser(0);
}

void loop() {

  ButtonState state = btn.getState();
  // Serial.print(state);
  // Serial.print("\n");
  if (state == PressedShort) {
    Serial.print("store value: ");
    Serial.print(store.getPreset(0));
    Serial.print("\n");
  } else if (state == PressedLong) {
    store.setPreset(0, 99);
  }
  
  delay(LOOP_DURATION_MS);
}
