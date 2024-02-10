#include "Arduino.h"
#include "TableMover.h"
#include <Servo.h>

TableMover::TableMover(int pin) {
  servo = new Servo();
  servo->attach(pin);
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