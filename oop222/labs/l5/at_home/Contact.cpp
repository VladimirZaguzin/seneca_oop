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


  Contact::Contact(const Contact& crs){
	  int i = 0;
	  if (crs.isEmpty()){
		  this->setEmpty();

	  }

	  else{

		  strcpy(_name, crs._name);
		  _noPN = crs._noPN;
		  _pn = new PhoneNumber[crs._noPN];

			  for (i = 0; i < _noPN; i++) {
				  _pn[i] = crs._pn[i];
			  }

		  }
}
  
  Contact& Contact::operator=(const Contact& C){
	  int i = 0;
	  if (this != &C){

		  delete[] _pn;
		  //Contact(C);
		  strcpy(_name, C._name);
		  _noPN = C._noPN;
		  _pn = new PhoneNumber[C._noPN];

		  for (i = 0; i < _noPN; i++) {
			  _pn[i] = C._pn[i];
		  }


	  }
	  return *this;
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