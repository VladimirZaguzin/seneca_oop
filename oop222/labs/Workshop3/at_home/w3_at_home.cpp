// OOP244 Workshop 3: Dynamic Memory
// File	w3_at_home.cpp
// Version 1.0
// Date	2015/05/30
// Author	A.C Coder
// Description
///////////////////////////////////////////////////////////


#include <iostream>
#include <cstring>
#include "Weather.h"
using namespace std;
using namespace sict;
double findLow(const char* qDate, Weather *wData, int n);
int main(){
  int n; //the count of days worth of weather
  // initialize the weather pointer here


  cout << "Weather Data\n";
  cout << "=====================" << endl;
  cout << "Days of Weather: ";
  cin >> n;
  cin.ignore();
  // allocate dynamic memory here

  for (int i = 0; i < n; i++){
    char date_description[7];
    double high = 0.0, low = 0.0;

    // ... add code to accept user input for
    //weather


  }
  cout << endl;
  cout << "Weather report:\n";
  cout << "======================" << endl;

  for (int i = 0; i < n; i++){
    weather[i].display();
  }

  //accept user input for the date to find
  //(in this example stored in char query[7])
  // and display the found low temprature.
  double low = findLow(query, weather, n);
  cout << "Low temperature : " << low << endl;

  // deallocate dynamic memory here


  return 0;

}

/*
Output Example:
Weather Data
=====================
Days of Weather: 3
Enter date: Oct/1
Enter high: 15
Enter low : 10
Enter date: Nov/13
Enter high: 10
Enter low : 1.1
Enter date: Dec/15
Enter high: 5.5
Enter low : -6.5

Weather report:
======================
Oct/1_______15.0__10.0
Nov/13______10.0___1.1
Dec/15_______5.5__-6.5

Enter the date you are looking for: Nov/13
Low temperature : 1.1
*/
