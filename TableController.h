#ifndef TABLECONTROLLER_H
#define TABLECONTROLLER_H

#include "ServoConfig.h"
#include "UltrasonicConfig.h"

#include "appsettings.h"
#include "DistanceMeter.h"
#include "TableMover.h"
#include "MoveDirection.h"


class TableController {
  private:
    DistanceMeter* meter;// = new DistanceMeter(PIN_ULTRASONIC_TRIGGER, PIN_ULTRASONIC_ECHO);
    TableMover* mover;// = new TableMover(PIN_SERVO);

    void printStatus(int pos, int current);

  public: 
    MoveDirection direction = None;
    
    TableController(UltrasonicConfig* sonic, ServoConfig* servo) {
      meter = new DistanceMeter(sonic->trigger, sonic->echo);
      mover = new TableMover(servo->pin);
    }
    
    int getCurrentPosition();
    MoveDirection goToPosition(int pos);
    MoveDirection stop();
};

#endif