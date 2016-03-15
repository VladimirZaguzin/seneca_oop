#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__
#include <iostream>
namespace sict{
  class Account{
    char _name[41];
    double _balance;
  public:
    Account();
    Account(const char name[], double balance = 0.0);
    Account(double balance);
    void display()const;
  };
};

#endif
