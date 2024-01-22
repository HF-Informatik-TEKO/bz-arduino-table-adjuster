#include "appsettings.h"
#include "TableAdjuster.h"

TableAdjuster table;

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.println("Program Start");
  table = TableAdjuster();
  // TODO: Falsify appsettings values. e.g. more active presets than default values. etc.
}

void loop() {
  table.cycle();
  delay(LOOP_DURATION_MS);
}