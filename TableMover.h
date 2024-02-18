#ifndef TABLEMOVER_H
#define TABLEMOVER_H

#include "Servo.h"
#include "MoveDirection.h"

#include "ConfigServo.h"

class TableMover {
    private:
      Servo* servo;
      int stopPos;
      int upPos;
      int downPos;

      void moveUp();
      void moveDown();
      void moveStop();

    public: 
      TableMover(ConfigServo* servo);
      void moveTable(MoveDirection direction);
};

#endif