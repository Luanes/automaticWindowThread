#ifndef CONFIGURATION_H
#define CONFIGURATION_H

class Configuration {
  public:
    Configuration();
    virtual ~Configuration();

	int getMaxTemp();
	void setMaxTemp(int temp);
	int getMinTemp();
	void setMinTemp(int temp);
	bool isAutomaticDay();
	void setAutomaticDay(bool aut);
	bool isAutomaticNight();
	void setAutomaticNight(bool aut);

  private:
	int tempMax;
	int tempMin;
	bool isAutDay;
	bool isAutNight;
	

};
#endif /* CONFIGURATION_H_H */
