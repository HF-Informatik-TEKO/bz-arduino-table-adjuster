#ifndef TABLEMOVER_H
#define TABLEMOVER_H

#include "Servo.h"
#include "MoveDirection.h"

class TableMover {
    private:
      Servo* servo;

      void moveUp();
      void moveDown();
      void moveStop();

    public: 
      TableMover(int pin);
      void moveTable(MoveDirection direction);
      void move(int degree);
};

#endif