# bz-arduino-table-adjuster
This is a Arduino project for the subject "MicroComputerTechnik" (MCT) at TEKO.

## General
This library is for controlling a height adjustable Table which can not move to certain heights on it's own. A servo motor will control the switch on your table and you can set a certain height as present for the table adjuster to take care. After pressing a preset-button, the table adjuster will move your table as long as it needs in the certain direction till it hits the wanted distance. The distance is measured by a ultrasonic-distance-meter. Different user profiles helps handle multiple presets.
With the Builder, we can easily setup the table-adjuster by passing all neccessary infos to it (pins, default heights, tolerances, etc.).
The table-adjuster can handle 5 different users with each 5 preset-buttons.

### Safety
For your own safety it's best to setup and properly configure the emergency-button.
After hitting the emergency-button, the table-adjuster will stop immediately any action and returns to a neutral state where all processes remain paused.
Only after pressing the emergency-button again, the table-adjuster will listen to any inputs.

## Dependencies
This library uses the "Servo.h" library to control the servo motor. [GitHub](https://github.com/arduino-libraries/Servo)

## Material List
- LEDs (green, yellow, red) -> status lights
- Ultrasonic sensor -> distance measuring
- Servo-motor -> table input
- Buttons -> safety-switch, presets, user-switch
- Breadboard
- Cables (div)
- Resistors (div)

## Builder Default Values
```cpp
adjuster = &builder
    .setPinBtnUser(53)
    .setPinBtnPresets(0, 51)
    .setPinBtnPresets(1, 50)
    .setPinBtnEmergency(52)

    .setHeightTolerance(2)
    .setPinUltrasonicTrigger(48)
    .setPinUltrasonicEcho(49)

    .setPinStatusLedRed(45)
    .setPinStatusLedYellow(46)
    .setPinStatusLedGreen(47)

    .setPinServo(44)
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
```

## Example Code

```cpp
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
    .setPinBtnEmergency(52)

    .setHeightTolerance(2)
    .setPinUltrasonicTrigger(48)
    .setPinUltrasonicEcho(49)

    .setPinStatusLedRed(45)
    .setPinStatusLedYellow(46)
    .setPinStatusLedGreen(47)

    .setPinServo(44)
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
```
