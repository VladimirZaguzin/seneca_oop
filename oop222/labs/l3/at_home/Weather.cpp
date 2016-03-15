/*Weather.cpp*/
//  includes go here
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "Weather.h"


namespace sict{

	// sict namespace
	// set
	void Weather::set(const char* date, double highTemp, double lowTemp){
		strcpy(_date, date);
		_highTemp = highTemp;
		_lowTemp = lowTemp;

	};

	//getDate
	char* Weather::getDate() const {
		return (char*)_date;
	};
	// getLowTemp

	double Weather::getLowTemp() const {
		return _lowTemp;
	};

	// display
	void Weather::display() const{
		cout << left << setw(10) << setfill('_') << _date;

		cout << right << setw(6) << setfill('_') << fixed << setprecision(1) << _highTemp;

		cout << right << setw(6) << setfill('_') << fixed << setprecision(1) << _lowTemp << endl;
		
	};


}
