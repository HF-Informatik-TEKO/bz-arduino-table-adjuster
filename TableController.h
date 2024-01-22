#ifndef TABLECONTROLLER_H
#define TABLECONTROLLER_H

#include "appsettings.h"
#include "DistanceMeter.h"
#include "TableMover.h"
#include "MoveDirection.h"

class TableController {
  private:
    DistanceMeter meter = DistanceMeter(ULTRASONIC_TRIGGER, ULTRASONIC_ECHO);
    TableMover mover = TableMover();
    MoveDirection direction = None;

    // int abs(int number);

  public: 
    TableController();
    int getCurrentPosition();
    MoveDirection goToPosition(int pos);
    MoveDirection stop();
};

#endif