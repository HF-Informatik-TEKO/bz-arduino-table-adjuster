#ifndef TABLECONTROLLER_H
#define TABLECONTROLLER_H

#include "DistanceMeter.h"
#include "TableMover.h"
#include "MoveDirection.h"

#include "ConfigServo.h"
#include "ConfigUltrasonic.h"


class TableController {
  private:
    DistanceMeter* meter;
    TableMover* mover;
    int heightTolerance;

    void printStatus(int pos, int current);

  public: 
    MoveDirection direction = None;
    
    TableController(ConfigUltrasonic* sonic, ConfigServo* servo);    
    int getCurrentPosition();
    MoveDirection goToPosition(int pos);
    MoveDirection stop();
};

#endif