#include "HardwareSerial.h"
#include "Arduino.h"
#include "TableController.h"

TableController::TableController() {
  direction = None;
}

int TableController::getCurrentPosition() {
  return meter.getDistance();
}

MoveDirection TableController::goToPosition(int pos) {
  int currentPosition = getCurrentPosition();
  int wayToMove = currentPosition - pos;

  Serial.print("TableController: ");
  Serial.print("Soll: ");
  Serial.print(pos);
  Serial.print(" | IST: ");
  Serial.println(currentPosition);


  if (abs(wayToMove) <= HEIGHT_TOLERANCE) {
    direction = None;
  } else if (wayToMove < 0) {
    direction = Down;
  } else {
    direction = Up;
  }

  mover.moveTable(direction);
  return direction;
}

MoveDirection TableController::stop() {
  mover.moveTable(None);
  return None;
}