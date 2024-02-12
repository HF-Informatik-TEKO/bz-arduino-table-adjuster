#include "Arduino.h"
#include "TableMover.h"

TableMover::TableMover(ServoConfig* config) {
  servo = new Servo();
  servo->attach(config->pin);
  this->upPos = config->upPos;
  this->stopPos = config->stopPos;
  this->downPos = config->downPos;
}

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
  servo->write(150);
}

void TableMover::moveDown() {
  Serial.println("TableMover: move down");
  servo->write(30);
}

void TableMover::moveStop() {
  Serial.println("TableMover: move stop");
  servo->write(90);
}