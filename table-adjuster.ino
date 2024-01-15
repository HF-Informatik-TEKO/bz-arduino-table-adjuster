#include "appsettings.h"
#include "PresetController.h"

PresetController controller;

void setup() {
  Serial.begin(9600);
  Serial.println("Program Start");
  controller = PresetController();
  // TODO: Falsify appsettings values. e.g. more active presets than default values. etc.
}

void loop() {
  WorkState state = controller.getState();

  if (state != NoWorkState) {
    Serial.print(state);
    Serial.print("\n");
  }

  if (state == GoToHeight) {
    int val = controller.getPresetValue();
    Serial.println(val);
  }
  if (state == SetHeight) {
    controller.setPresetValue(99);
  }

  delay(LOOP_DURATION_MS);
}
