#ifndef TABLECONTROLLER_H
#define TABLECONTROLLER_H

class TableController {
    private:
      DistanceMeter meter;
      TableMover mover;
      MoveDirection direction;

    public: 
      TableController();
      int getCurrentPosition();
      void goToPosition(int pos);
};

#endif