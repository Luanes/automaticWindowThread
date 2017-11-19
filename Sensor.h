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
    bool isWindowClose();
    bool isRaining();
    int getTemperature();
    bool isDay();
    
  private:
   int aux_getTemperature();
   
};
#endif /* SENSOR_H */