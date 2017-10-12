#ifndef BRAIN_H
#define BRAIN_H

#include "Sensor.h"

class Brain {
  public:
    Brain();
    virtual ~Brain();
    int test();

  private:
    Sensor sensor;  

};
#endif /* BRAIN_H */