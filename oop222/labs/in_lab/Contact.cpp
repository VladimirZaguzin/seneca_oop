#include <cstring>
#include <iostream>
#include "Contact.h"
using namespace std;

namespace sict{


  void Contact::display()const{
	  int i = 0;


    //display the name and go to new line
	  cout << _name << endl;
    // loop through elements of _pn up to _noPN and display them one by one
	  for (i = 0; i < _noPN; i++){
		  bool n = true;
		  _pn[i].display(n);
	  }
    // draw a 40 char line using '-' and go to new line
	  for (i = 0; i < 40; i++){
		  cout << "-";
	  }
	  cout << endl;
  }

  Contact::Contact(){
	  setEmpty();
  }

  Contact::Contact(const char* name, int noPN){
	  
	  if (strlen(name)>40){
		  strncpy(_name, name, 40);
		  _name[40] = '\0';
	  }
	  else{
		  strcpy(_name, name);
	  }

	  _noPN = noPN;
	  _pn = new PhoneNumber[_noPN];
	
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
