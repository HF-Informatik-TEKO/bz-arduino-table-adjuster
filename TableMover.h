#ifndef TABLEMOVER_H
#define TABLEMOVER_H

#include "MoveDirection.h"

class TableMover {
    private:
      void moveUp();
      void moveDown();
      void moveStop();

    public: 
      void moveTable(MoveDirection direction);
};

#endif