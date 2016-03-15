// OOP244 Workshop 8: Derived Classes
// File	w8_in_lab.cpp
// Version 1.0
// Date	2015/11/18
// Author	Franz Newland, Eden Burton, Fardad soleimanloo
// Description
// This file demonstrates the client module of w8 
/////////////////////////////////////////////////////

#include <iostream>
#include "SuperHero.h"
using namespace sict;
using namespace std;

int main(){
  SuperHero p;
  SuperHero w("wimpy", -10, 5);
  cout << p << endl << w << endl;

  SuperHero h("hercules", 100, 5);
  SuperHero hClone(h);
  cout << h << endl << hClone << endl;

  SuperHero sm("Superman", 130, 5);
  cout << sm << endl;

  cout << "Superman battles Hercules clone!" << endl;
  sm *= hClone;
  cout << sm << endl << hClone << endl;

  cout << "Hercules battles Superman!" << endl;
  h *= sm;
  cout << sm << endl << h << endl;
  return 0;
}
