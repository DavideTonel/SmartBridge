#ifndef __PHOTORESISTOR__
#define __PHOTORESISTOR__

#include "ILightSensor.h"

class Photoresistor : public ILightSensor {
private:
    int pin;
    // rimettere 25
    int threshold = 320;
    
public:
    Photoresistor(const int pin);
    void setThreshold(const int threshold);
    // true when the read is less than threshold
    bool isDark();
};

#endif