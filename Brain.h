#ifndef BRAIN_H
#define BRAIN_H

#include "Sensor.h"

class Brain {
  public:
    Brain();
    virtual ~Brain();
    void test();

  private:
    Sensor sensor;  

};
#endif /* BRAIN_H */