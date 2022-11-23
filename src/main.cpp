#include <Arduino.h>
#include "tasks/LightSensorTask.h"
#include "tasks/MovementDetectionTask.h"
#include "tasks/SmartLampTask.h"
#include "tasks/WaterLevelMonitorTask.h"
#include "schedulers/Scheduler.h"
#include "tasks/PrintInfo.cpp"
#include "tasks/SignalingTask.h"
#include "tasks/WarningSignalingTask.h"


PrintInfo* p;

Scheduler* s;
SystemInfo* info;

LightSensorTask* lsens;
MovementDetectionTask* mov;
WaterLevelMonitorTask* waterLevelMonitor;

SmartLampTask* smartlamp;

SignalingTask* ledGood;
WarningSignalingTask* ledWarning;

void setup() {
  Serial.begin(9600);
  /*
  Serial.println("start");
  info = info->getInstance();
  Serial.println("info: ");

  Serial.print("Dark: ");
  Serial.println(info->isDark());

  Serial.print("Movement: ");
  Serial.println(info->isMovementDetected());
  */

  s = new Scheduler();
  s->init(200);

  // SMARTLAMP
  lsens = new LightSensorTask(A1);
  lsens->init(400);
  s->addTask(lsens);

  mov = new MovementDetectionTask(2);
  mov->init(1000);
  s->addTask(mov);

  smartlamp = new SmartLampTask(12);
  smartlamp->init(400);
  s->addTask(smartlamp);
  // SMARTLAMP


  // BRIDGE
  waterLevelMonitor = new WaterLevelMonitorTask(6, 5);
  waterLevelMonitor->init(400);
  s->addTask(waterLevelMonitor);

  ledGood = new SignalingTask(13);
  ledGood->init(400);
  s->addTask(ledGood);

  ledWarning = new WarningSignalingTask(8);
  ledWarning->init(400);
  s->addTask(ledWarning);
  // BRIDGE


  p = new PrintInfo();
  p->init(200);
  //s->addTask(p);
}

void loop() {
  s->schedule();
}