#include "HardwareSerial.h"
#include "Arduino.h"
#include "DistanceMeter.h"

int DistanceMeter::getDistance() {
  digitalWrite(pinTrigger, LOW);
  delay(10);
  digitalWrite(pinTrigger, HIGH);
  delay(20);
  digitalWrite(pinTrigger, LOW);

  long echoTime = pulseIn(pinEcho, HIGH);
  float distance = calculateDistance(echoTime);
  
  return (int)distance;
}

float DistanceMeter::calculateDistance(long time) {
  return time / 2 * sonicSpeed;
}
