#include "HardwareSerial.h"
#include "Arduino.h"
#include "TableController.h"

// TableController::TableController() {
// }

int TableController::getCurrentPosition() {
  return meter->getDistance();
}

MoveDirection TableController::goToPosition(int pos) {
  int currentPosition = getCurrentPosition();
  int wayToMove = currentPosition - pos;

  printStatus(pos, currentPosition);

  bool hasReachedHeight = abs(wayToMove) <= HEIGHT_TOLERANCE;
  if (hasReachedHeight) {
    direction = None;
  } else if (wayToMove < 0) {
    direction = Down;
  } else {
    direction = Up;
  }

  mover->moveTable(direction);
  return direction;
}

MoveDirection TableController::stop() {
  mover->moveTable(None);
  return None;
}

void TableController::printStatus(int pos, int currentPos) {
  Serial.print("TableController: ");
  Serial.print("Soll: ");
  Serial.print(pos);
  Serial.print(" | IST: ");
  Serial.println(currentPos);
}