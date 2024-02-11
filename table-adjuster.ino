#include "TableAdjusterBuilder.h"

TableAdjuster* adjuster;

void setup() {
  Serial.begin(9600);
  Serial.println();

  TableAdjusterBuilder builder;
  adjuster = &builder
    .setPinBtnUser(49)
    .setPinBtnPresets(0, 47)
    .setPinBtnPresets(1, 45)
    .setPinUltrasonicTrigger(5)
    .setPinUltrasonicEcho(6)
    .setHeightTolerance(2)
    .setPinStatusLedRed(52)
    .setPinStatusLedGreen(51)
    .setPinStatusLedYellow(50)
    .setPinServo(43)
    .setActiveUsers(2)
    .setActivePresets(2)
    .setDefaultUser(0)
    .setDefaultValues(0, new int[2] {10, 20})
    .setDefaultValues(1, new int[2] {15, 25})
    .setLoopDurationMs(50)
    .setTimeoutDurationMs(3000)
    .setButtonLongPressMs(1000)
    .build();

  Serial.println("Program Start");
}

void loop() {
  adjuster->cycle();
  adjuster->cycleDelay();
}