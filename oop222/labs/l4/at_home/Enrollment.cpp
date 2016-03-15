#include <iostream>
#include <cstring>
#include "Enrollment.h"
using namespace std;
namespace sict{
	//done 
	bool Enrollment::valid()const{
		return _name[0] && !!_name[0];
	}
	//done
	void Enrollment::setEmpty(){
		_name[0] = '\0';
		_code[0] = '\0';
		_year = 0;
		_semester = 0;
		_slot = 0;
		_enrolled = false;
	}
	// done
	bool Enrollment::isEnrolled() const{
		return _enrolled;
	}
	void Enrollment::set(const char* n, const char* c, int y, int t, int s, bool en){
		if (y >= 2015 && (t >0 && t<4) && s>0 && s<6 && n != (char*)0 && n[0] && c != (char*)0 && c[0]){
			_year = y;
			_semester = t;
			_slot = s;
			strncpy(_name, n, 30);
			strncpy(_code, c, 10);
			_enrolled = en;

		}
		else{
			setEmpty();
		}
	}
	// done
	void Enrollment::display(bool nameOnly)const{
		if (valid()){
			cout << _name;
			if (!nameOnly){
				cout << endl << _code << ", Year: " << _year << " semester: " << _semester << " Slot: " << _slot << endl;
				cout << "Status: " << (isEnrolled() ? "E" : "Not e") << "nrolled." << endl;
			}
		}
		else{
			cout << "Invalid enrollment!" << endl;
		}
	}

	void Enrollment::withdraw(){
		_enrolled = false;
	
	}


	bool Enrollment::hasConflict(const Enrollment &other) const{
		if (other._year != 0 && _year != 0 && other._semester != 0 && _semester != 0 && other._slot != 0 && _slot != 0){
			if (other._year == _year && other._semester == _semester && other._slot == _slot){
				return true;
			}
		}
		return false;

	}


	int Enrollment::enrol(const Enrollment* enrollments, int size){
		int i = 0;
		for (i = 0; i < size; i++){
			if (this->hasConflict(enrollments[i])){
				return i + 1;
			}

		}
		_enrolled = true;

		return 0;
	}


}
