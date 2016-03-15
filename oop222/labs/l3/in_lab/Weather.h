// compilation safegaurds
#ifndef SICT_ACCOUNTNUMBER_H_
#define SICT_ACCOUNTNUMBER_H_

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
	};

}
#endif
