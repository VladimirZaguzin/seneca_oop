#include <iostream>
#include "Enrollment.h"
using namespace std;
namespace sict{

  bool Enrollment::valid()const{
    return _name[0] && !!_name[0];
  }
  void Enrollment::setEmpty(){
    _name[0] = '\0';
    _code[0] = '\0';
    _year = 0;
    _semester = 0;
    _slot = 0;
    _enrolled = false;
  }
  bool Enrollment::isEnrolled() const{
    return _enrolled;
  }
  void Enrollment::set(const char* n, const char* c, int y, int s , int t, bool en){
	  if( y >= 2015 && (t >0 && t<6) && s>0 && s<4 && n != (char*)0 && n[0] && c!=(char*)0 && c[0]){
		  _year = y;
		  _semester = t;
		  _slot =s;
		  strncpy(_name, n, 30);
		  strncpy(_code, c,10);
		  _enrolled = en;

	  }
	  else{
	  setEmpty();
	  }
  }
  bool Enrollment::hasConflict(const Enrollment &other) const{
	  return valid() && other.valid() && (other._year == _year && other._semester == _semester && other._slot == _slot);
  }

  Enrollment:: Enrollment(){
  setEmpty();
  }

  Enrollment:: Enrollment(const char* name, const char* code, int year, int semester , int time){
	  set(name, code, year, semester, time,false);
  }

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
}



