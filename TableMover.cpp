#include "Arduino.h"
#include "TableMover.h"

void TableMover::moveTable(MoveDirection direction) {
  if (direction == Up) {
    moveUp();
  } else if (direction == Down) {
    moveDown();
  } else {
    moveStop();
  }
}

void TableMover::moveUp() {
  Serial.println("TableMover: move up");
}

void TableMover::moveDown() {
  Serial.println("TableMover: move down");
}

void TableMover::moveStop() {
  Serial.println("TableMover: move stop");
}