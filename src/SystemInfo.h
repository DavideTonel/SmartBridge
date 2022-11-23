#ifndef __SYSTEMINFO__
#define __SYSTEMINFO__

#include "SystemState.h"

class SystemInfo {
private:
    float waterLevel;
    SystemState systemState;

    // non lo so
    bool movementDetected;
    bool dark;

    static SystemInfo* instance;

    SystemInfo();

public:
    static SystemInfo* getInstance();

    float getWaterLevel();

    SystemState getSystemState();

    void setWaterLevel(const float value);

    void setSystemState(const SystemState state);


    // non lo so
    void setMovementDetected(bool value);
    void setDark(bool value);

    bool isMovementDetected();
    bool isDark();
};

#endif