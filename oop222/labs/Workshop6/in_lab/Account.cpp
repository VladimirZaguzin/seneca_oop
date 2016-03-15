#include "cstring"
#include "iomanip"
#include "Account.h"
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
  void Account::display()const{
    cout << _name << ": $" << setprecision(2) << fixed << _balance;
  }

}