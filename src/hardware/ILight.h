#ifndef __ILIGHT__
#define __ILIGHT__

class ILight {
public:
    virtual void switchOn() = 0;
    virtual void switchOff() = 0;
};

#endif
