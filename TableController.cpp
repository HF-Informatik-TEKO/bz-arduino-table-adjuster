#include "HardwareSerial.h"
#include "Arduino.h"
#include "TableController.h"

TableController::TableController() {
  direction = None;
}

int TableController::getCurrentPosition() {
  return meter.getDistance();
  // return 110;
}

MoveDirection TableController::goToPosition(int pos) {
  int currentPosition = getCurrentPosition();
  int wayToMove = currentPosition - pos;

  Serial.print("TableController: ");
  Serial.print("Soll: ");
  Serial.print(pos);
  Serial.print(" | IST: ");
  Serial.println(currentPosition);


  if (abs(wayToMove) < 5) {
    direction = None;
  } else if (wayToMove < 5) {
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