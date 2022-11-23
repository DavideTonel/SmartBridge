#ifndef __ILIGHTSENSOR__
#define __ILIGHTSENSOR__

class ILightSensor {
public:
    virtual void setThreshold(const int threshold) = 0;
    virtual bool isDark() = 0;
};

#endif