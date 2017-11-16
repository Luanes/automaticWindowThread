#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include "Connection.h"

class Configuration {
  public:
    Configuration();
    virtual ~Configuration();

	void getConfiguration();
	int getMaxTemp();
	void setMaxTemp(int temp);
	int getMinTemp();
	void setMinTemp(int temp);
	bool isAutomaticDay();
	void setAutomaticDay(bool aut);
	bool isAutomaticNight();
	void setAutomaticNight(bool aut);

  private:
	Connection connect;
	int tempMax;
	int tempMin;
	bool isAutDay;
	bool isAutNight;
	

};
#endif /* CONFIGURATION_H_H */
