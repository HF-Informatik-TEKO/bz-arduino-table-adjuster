#include "Arduino.h"
#include "TableMover.h"

TableMover::TableMover(ConfigServo* config) {
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
  servo->write(upPos);
}

void TableMover::moveDown() {
  Serial.println("TableMover: move down");
  servo->write(downPos);
}

void TableMover::moveStop() {
  Serial.println("TableMover: move stop");
  servo->write(stopPos);
}
