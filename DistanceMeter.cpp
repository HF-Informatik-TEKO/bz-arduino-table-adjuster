#include "Arduino.h"
#include "DistanceMeter.h"

DistanceMeter::DistanceMeter(int trigger, int echo) {
  pinTrigger = trigger;
  pinEcho = echo;
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}

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
