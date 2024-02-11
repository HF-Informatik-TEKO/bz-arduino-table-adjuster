#ifndef TABLEADJUSTER_H
#define TABLEADJUSTER_H

#include "PresetController.h"
#include "TableController.h"
#include "Statuslight.h"
#include "WorkState.h"

class TableAdjuster {
  private:
    PresetController* preset;
    TableController* table;
    StatusLight* status;
    WorkState state;
    int height;
    int timeoutCounter;
    int timeoutDurationMs;
    int loopDurationMs;

    void moveTable();
    void setHeight();
    void resetState();
    void changeState(WorkState newState);
    void timeout(String className);

  public:
    TableAdjuster(
      DurationsConfig* durationsConfig, 
      PresetController* preset, 
      TableController* table, 
      StatusLight* status
    );
    void cycleDelay();
    void cycle();
};

#endif