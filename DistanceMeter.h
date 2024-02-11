#ifndef DISTANCEMETER_H
#define DISTANCEMETER_H

class DistanceMeter {
  private:
    float sonicSpeed = 0.035;
    int pinTrigger;
    int pinEcho;

  public: 
    DistanceMeter(int trigger, int echo);
    int getDistance();
    float calculateDistance(long time);
};

#endif