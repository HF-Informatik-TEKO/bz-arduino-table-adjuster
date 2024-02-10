#include "appsettings.h"
#include "TableAdjuster.h"

TableAdjuster* adjuster;

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.println("Program Start");

  adjuster = new TableAdjuster();
  // TODO: Falsify appsettings values. e.g. more active presets than default values. etc.
}

void loop() {
  adjuster->cycle();
  delay(LOOP_DURATION_MS);
}