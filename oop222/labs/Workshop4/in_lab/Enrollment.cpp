#include <iostream>


  bool Enrollment::valid()const{
    return _name[0] && !!_name[0];
  }
  void Enrollment::setEmpty(){
    _name[0] = 0;
    _code[0] = 0;
    _year = 0;
    _semester = 0;
    _slot = 0;
    _enrolled = false;
  }
  bool Enrollment::isEnrolled() const{
    return _enrolled;
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




