// OOP244 Workshop 10 - Templates 
// File: w10_at_home.cpp
// Version: 1.0
// Date: 2015/12/01
// Author: Fardad Soleimanloo
// Description:
// This file tests in-lab section of your workshop
/////////////////////////////////////////////
#include <iostream>
#include "Validate.h"
#include "Weather.h"
using namespace sict;
int main() {
  Weather min(-30.0);
  Weather max(50.0);
  Weather test1(-100.0);
  Weather test2(0.0);
  Weather test3(100.0);

  if (validate(min, max, test1)){
    std::cout << "test1 is valid" << std::endl;
  }
  else {
    std::cout << "test1 is invalid" << std::endl;
  }

  if (validate(min, max, test2)){
    std::cout << "test2 is valid" << std::endl;
  }
  else {
    std::cout << "test2 is invalid" << std::endl;
  }

  if (validate(min, max, test3)){
    std::cout << "test3 is valid" << std::endl;
  }
  else {
    std::cout << "test3 is invalid" << std::endl;
  }
  return 0;
}


