#include "cstring"
#include "iomanip"
#include "Account.h"
#include <iostream>

using namespace std;
namespace sict{
  Account::Account(){
    _name[0] = 0;
    _balance = 0;
  }
  Account::Account(double balance){
    _name[0] = 0;
    _balance = balance;
  }

  Account::Account(const char name[], double balance){
    strncpy(_name, name, 40);
    _name[40] = 0;
    _balance = balance;
  }
  ostream& Account::display(ostream& os)const{
    return os << _name << ": $" << setprecision(2) << fixed << _balance;
  }

  Account& Account::operator=(const char* src){
	  strncpy(_name, src, 40);
	  _name[40] = 0;
	  return *this;
  }

  Account&  Account::operator+=(const Account& src){
	  _balance += src._balance;
	  return *this;
  }

  Account Account::operator+(const Account &src2){

	  Account sum = *this;

		sum._balance += src2._balance;

	return sum;
  }

  double operator+=(double& val, const Account& src){	 
	  return   val += src._balance ;
 }

  std::ostream& operator<<(ostream& os, const Account& src){
	  return src.display(os);
  }


}