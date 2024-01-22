#include "HardwareSerial.h"
#include "Arduino.h"
#include "DistanceMeter.h"

DistanceMeter::DistanceMeter(int trigger, int echo) {
  // Original Value From Book: const float SONIC_SPEED = 0.03432;
  SONIC_SPEED = 0.035;
  pinTrigger = trigger;
  pinEcho = echo;
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}

int DistanceMeter::getDistance() {
  digitalWrite(pinTrigger, LOW);
  delay(5);
  digitalWrite(pinTrigger, HIGH);
  delay(10);
  digitalWrite(pinTrigger, LOW);

  long echoTime = pulseIn(pinEcho, HIGH);
  float distance = calculateDistance(echoTime);
  
  return (int)distance;
}

float DistanceMeter::calculateDistance(long time) {
  return time / 2 * SONIC_SPEED;
}
