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
	std::ostream& display(std::ostream& os = std::cout)const;

	Account operator+(const Account& src2);
	Account&  operator=(const char* src);
	Account&  operator+=(const Account& src);


	friend double operator+=(double& val, const Account& src);

  };

  std::ostream& operator<<(std::ostream& os, const Account& src);
};

#endif
