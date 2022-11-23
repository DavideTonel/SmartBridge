#ifndef __IPIR__
#define __IPIR__

class IPir {
public:
    virtual void calibrate() = 0;
    virtual bool isDetection() = 0;
};

#endif