#include "TableAdjusterBuilder.h"

TableAdjuster* adjuster;

void setup() {
  Serial.begin(9600);
  Serial.println();

  TableAdjusterBuilder builder;
  adjuster = &builder
    .setPinBtnUser(49)
    .setPinBtnPresets(0, 51)
    .setPinBtnPresets(1, 53)
    .setPinBtnEmergency(47)

    .setHeightTolerance(2)
    .setPinUltrasonicTrigger(41)
    .setPinUltrasonicEcho(42)

    .setPinStatusLedRed(31)
    .setPinStatusLedYellow(33)
    .setPinStatusLedGreen(35)

    .setPinServo(39)
    .setMoveUpAngle(120)
    .setMoveStopAngle(90)
    .setMoveDownAngle(60)

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