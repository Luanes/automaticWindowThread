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

    void setConditionstoSimulate();
    
  private:

};
#endif /* SENSOR_H */