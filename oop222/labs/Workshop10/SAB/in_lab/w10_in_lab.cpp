// OOP244 Workshop 10 - Templates 
// File: w10_in_lab.cpp
// Version: 1.0
// Date: 2015/12/01
// Author: Fardad Soleimanloo
// Description:
// This file tests in-lab section of your workshop
/////////////////////////////////////////////

#include <iostream>
#include "Validate.h"
using namespace sict;
int main() {
  int t1Values[] = { 28, 44, 12, 30 };
  int t1Max = 30;
  int t1Min = 20;
  double t2Values[] = { 28.0, 22.5, 15.8, 21.6 };
  double t2Max = 25.0;
  double t2Min = 20.0;
  char t3Values[] = { 'a', 'Z', 'M', 'm' };
  char t3Max = 'Q';
  char t3Min = 'g';

  for (int i = 0; i < 4; i++)
  {
    if (validate(t1Min, t1Max, t1Values[i])){
      std::cout << t1Values[i] << " is valid" << std::endl;
    }
    else {
      std::cout << t1Values[i] << " is invalid" << std::endl;
    }
    if (validate(t2Min, t2Max, t2Values[i])){
      std::cout << t2Values[i] << " is valid" << std::endl;
    }
    else {
      std::cout << t2Values[i] << " is invalid" << std::endl;
    }
    if (validate(t3Min, t3Max, t3Values[i])){
      std::cout << t3Values[i] << " is valid" << std::endl;
    }
    else {
      std::cout << t3Values[i] << " is invalid" << std::endl;
    }
  }
  std::cout << std::endl;
  return 0;
}
