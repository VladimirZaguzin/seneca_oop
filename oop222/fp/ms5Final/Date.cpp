#include <iomanip>
#include <iostream>
#include <ctime>

using namespace std;
#include "Date.h"
#include "POS.h"
namespace sict{

	/*constructors*/

	Date::Date(){
		_dateOnly = false;
		set();
	}
	Date::Date(int year, int mon, int day){
		_dateOnly = true;
		set(year, mon, day, 0, 0);
	}
	Date::Date(int year, int mon, int day, int hour, int min){
		_dateOnly = false;
		set(year, mon, day, hour, min);
	}

	/*!constructors*/

	void Date::set(){
		time_t t = time(NULL);
		tm lt = *localtime(&t);
		_day = lt.tm_mday;
		_mon = lt.tm_mon + 1;
		_year = lt.tm_year + 1900;
		if (dateOnly()){
			_hour = _min = 0;
		}
		else{
			_hour = lt.tm_hour;
			_min = lt.tm_min;
		}
	}

	int Date::value()const{
		return _year * 535680 + _mon * 44640 + _day * 1440 + _hour * 60 + _min;
	}


	int Date::mdays()const{
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = _mon >= 1 && _mon <= 12 ? _mon : 13;
		mon--;
		return days[mon] + int((mon == 1)*((_year % 4 == 0) && (_year % 100 != 0)) || (_year % 400 == 0));
	}

	

	/*random functions*/

	void Date::set(int year, int mon, int day, int hour, int min){

		_year = year;
		_mon = mon;
		_day = day;
		_hour = hour;
		_min = min;
		errCode(0);

	}

	bool Date::bad()const{
	
		return (_readErrorCode != 0)? true: false;
	}

	void Date::errCode(int errorCode){
			_readErrorCode = errorCode;
	}

	int Date::errCode()const{
		return _readErrorCode;
	}

	bool Date::dateOnly()const{
		return _dateOnly;
	};

	void Date::dateOnly(bool value){
		_dateOnly = value;
		if (_dateOnly){
			_hour = 0;
			_min = 0;
		}
	};



	/*!random functions*/

	/*operators*/

	bool Date::operator>=(const Date& D)const{
		return (this->value() >= D.value()) ? true : false;
	}

	bool Date::operator<=(const Date& D)const{
		return (this->value() <= D.value()) ? true : false;
	}

	bool Date::operator>(const Date& D)const{
		return (this->value() > D.value()) ? true : false;
	}

	bool Date::operator<(const Date& D)const{
		return (this->value() < D.value()) ? true : false;
	}

	bool Date::operator!=(const Date& D)const{
		return (this->value() != D.value()) ? true : false;
	}

	bool Date::operator==(const Date& D)const{	
		return (this->value() == D.value()) ? true : false;
	}

	std::istream& operator>>(std::istream& istr, Date& D){
		return D.read(istr);
	}
	std::ostream& operator<<(std::ostream& ostr, const Date& D){
		return D.write(ostr);
	}

	/*!operators*/

	/*read and write*/
	istream& Date::read(istream& istr){

				if (dateOnly()){
		

			istr >> _year;
			istr.ignore();
			istr >> _mon;
			istr.ignore();
			istr >> _day;

		}
		else{
			istr >> _year;
			istr.ignore();
			istr >> _mon;
			istr.ignore();
			istr >> _day;
			istr.ignore();
			istr >> _hour;
			istr.ignore();
			istr >> _min;

		}

		if (istr.fail()){
			errCode(1);
		}
		else{
			if (validateD(_year, _mon, _day, _hour, _min)){
				errCode(0);
			}
		}
		return istr;
	}
	ostream& Date::write(ostream& ostr)const{

	
		ostr << _year << "/" << internal << setfill('0') << setw(2) << _mon << "/" << internal << setfill('0') << setw(2) << _day;
		if (!_dateOnly){
			ostr << ", " << _hour << ":" << _min;

		}
	

		return ostr;
	}
	/*!read and write*/


	/*validation*/
	bool Date::validateD(int year, int mon, int day, int hour, int min){

		bool isValid = true;
		int maxDays = mdays();

		if (year < MIN_YEAR || year > MAX_YEAR){
			isValid = false;
			errCode(2);
		}
		else if (mon < 1 || mon>12){
			isValid = false;
			errCode(3);
		}
		else{
			maxDays = mdays();
			if (maxDays == -1 || day > maxDays || _day <= 0)
			{
				isValid = false;
				errCode(4);
			}
			if (!dateOnly()){
				if (hour < 0 || hour>23){
					isValid = false;
					errCode(5);
				}
				else if (min < 0 || min>59)
				{
					isValid = false;
					errCode(6);
				}
			}
			
			
		}
		return isValid;
	}

	/*!validation*/


}
