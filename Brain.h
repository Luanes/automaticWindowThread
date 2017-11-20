#ifndef BRAIN_H
#define BRAIN_H

#include "Sensor.h"
#include "Configuration.h"


class Brain {
  public:
    Brain();
    virtual ~Brain();
    void check();
    void update();
    void act();
    void setConfiguration(bool openW);
    void checkRain(Brain brain);

  private:
    Sensor sensor;  
    Configuration config;

    bool isAutomatic();

    bool rain;
    bool day;
    int temperatureNow;
    int temperatureMinimum;
    int temperatureMaximum;
    bool automaticOn;

};
#endif /* BRAIN_H */
