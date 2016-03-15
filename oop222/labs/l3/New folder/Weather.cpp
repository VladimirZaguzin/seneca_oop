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

		strcpy(_pdate, date);
		_phighTemp = highTemp;
		_plowTemp = lowTemp;


	};

	// getDate

	int* getDate() const {
		return &_date;
	}
// getLowTemp

	int* getLowTemp()const {
		return &_lowTemp;
	}


	




	// display
	void Weather::display() const{
		cout << left << setw(10) << setfill('_') << _date;

		cout << right << setw(6) << setfill('_')<<fixed << setprecision(1) << _highTemp;

		cout << right << setw(6) << setfill('_')<<fixed << setprecision(1) << _lowTemp << endl;
	};


}
