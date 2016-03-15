#include <cstring>
#include <iostream>
#include "Contact.h"
using namespace std;

namespace sict{

  void Contact::display()const{
    //display the name and go to new line
   
    // loop through elements of _pn up to _noPN and display them one by one

    // draw a 40 char line using '-' and go to new line
  }

  void Contact::read(){
    cout << "Contact Name: ";
    cin.getline(_name, 41, '\n');
    cout << "Please enter " << _noPN << " phone numbers: " << endl;
    for (int i = 0; i < _noPN; i++){
      cout << i + 1 << ": ";
      _pn[i].read();
    }
  }


  bool Contact::isEmpty()const{
    return _pn == (PhoneNumber*)0;
  }
  void Contact::setEmpty(){
    _name[0] = 0;
    _noPN = 0;
    _pn = (PhoneNumber*)0;// same as _pn = nullptr;
  }




}