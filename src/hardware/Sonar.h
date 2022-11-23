#ifndef __SONAR__
#define __SONAR__

#include "ISonar.h"

class Sonar : public ISonar {
private:
    const float vs = 331.5 + 0.6*20;
    int trigPin;
    int echoPin;
public:
    // forse prima echoPin
    Sonar(const int trigPin, const int echoPin);
    float getDistance();
};

#endif