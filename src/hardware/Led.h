#ifndef __LED__
#define __LED__

#include "ILight.h"

class Led: public ILight {
private:
    int pin;

public:
    Led(int pin);
    void switchOn();
    void switchOff();
};

#endif