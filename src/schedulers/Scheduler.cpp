#include <Arduino.h>
#include "Scheduler.h"
#include <TimerOne.h>

volatile bool timerFlag;

void timerHandler(void){
  timerFlag = true;
}

//int time = 0;

void Scheduler::init(int basePeriod){
  this->basePeriod = basePeriod;
  timerFlag = false;
  long period = 1000l*basePeriod;
  Timer1.initialize(period);
  Timer1.attachInterrupt(timerHandler);
  nTasks = 0;
}

bool Scheduler::addTask(ITask* task){
  if (nTasks < MAX_TASKS-1){
    taskList[nTasks] = task;
    nTasks++;
    return true;
  } else {
    return false; 
  }
}
  
void Scheduler::schedule(){   
  while (!timerFlag){}
  timerFlag = false;

  //time += basePeriod;
  //Serial.println(time);

  for (int i = 0; i < nTasks; i++){
    if (taskList[i]->isToExecute(basePeriod)){
      taskList[i]->tick();
    }
  }
}