#ifndef DISTANCEMETER_H
#define DISTANCEMETER_H

#include "UltrasonicConfig.h"

class DistanceMeter {
  private:
    float sonicSpeed = 0.035;
    int pinTrigger;
    int pinEcho;

  public: 
    DistanceMeter(UltrasonicConfig* sonic);
    int getDistance();
    float calculateDistance(long time);
};

#endif