#include "appsettings.h"
#include "TableAdjuster.h"
#include "TableAdjusterBuilder.h"

TableAdjuster* adjuster;

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.println("Program Start");

  // adjuster = new TableAdjuster();
  // TODO: Falsify appsettings values. e.g. more active presets than default values. etc.


  Builder builder;
  adjuster = &builder
    .setPinBtnPresets(0, 47)
    .setPinBtnPresets(1, 45)
    .setPinBtnUser(49)
    .setLoopDurationMs(50)
    .setTimeoutDurationMs(3000)
    .setButtonLongPressMs(1000)
    .setPinUltrasonicTrigger(5)
    .setPinUltrasonicEcho(6)
    .setHeightTolerance(2)
    .setPinStatusLedRed(52)
    .setPinStatusLedGreen(51)
    .setPinStatusLedYellow(50)
    .setPinServo(43)
    .build();
}

void loop() {
  adjuster->cycle();
  delay(LOOP_DURATION_MS);
}