#include "TableAdjusterBuilder.h"

TableAdjuster* adjuster;

void setup() {
  Serial.begin(9600);
  Serial.println();

  TableAdjusterBuilder builder;
  adjuster = &builder
    .setPinBtnUser(53)
    .setPinBtnPresets(0, 51)
    .setPinBtnPresets(1, 50)

    .setHeightTolerance(2)
    .setPinUltrasonicTrigger(48)
    .setPinUltrasonicEcho(49)

    .setPinStatusLedRed(45)
    .setPinStatusLedYellow(46)
    .setPinStatusLedGreen(47)

    .setPinServo(6)

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