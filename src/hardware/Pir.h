#ifndef __PIR__
#define __PIR__

#include "IPir.h"

class Pir : public IPir {
private:
    int pin;
public:
    Pir(const int pin);
    void calibrate();
    bool isDetection();
};

#endif