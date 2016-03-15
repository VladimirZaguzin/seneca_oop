// compilation safegaurds
#ifndef SICT_WEATHER_H_
#define SICT_WEATHER_H_

/*Weather.h*/
namespace sict{

	// sict namespace
	class Weather{
		// member variables
		char _date[7];
		double _highTemp;
		double _lowTemp;
	public:
		// member function
		void set(const char*, double, double);
		void display() const;
	

		char* getDate() const;

		double getLowTemp() const;
	};

}
#endif

