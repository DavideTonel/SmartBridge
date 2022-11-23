#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "../tasks/ITask.h"

#define MAX_TASKS 50

class Scheduler {
  
  int basePeriod;
  int nTasks;
  ITask* taskList[MAX_TASKS];  

public:
  void init(int basePeriod);  
  virtual bool addTask(ITask* task);  
  virtual void schedule();
};

#endif