#ifndef SENSOR_H
#define SENSOR_H

#include <wiringPi.h>

class Sensor {
  public:
    Sensor();
    virtual ~Sensor();
    int testing();
    void openWindow();
    void closeWindow();
    bool isWindowOpen();
    
  private:

};
#endif /* SENSOR_H */