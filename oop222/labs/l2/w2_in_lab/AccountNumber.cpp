// OOP244 Workshop 2: Compound types and privacy
// File	???????
// Version 1.0
// Date	???????????
// Author	?????????
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name			Date		Reason
// 
///////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
using namespace std;
#include "AccountNumber.h"

namespace sict{
  //class implemetation goes here
	void AccountNumber::setName(const char name[]){
		strcpy(_name, name);
	};

	void AccountNumber::setAccountNumber(int bankCode, int branchCode, int accountNumber){

		_branchCode = branchCode;
		_bankCode = bankCode;
		_accountNumber = accountNumber;

		if ((bankCode >= MIN_BANKCODE && bankCode <= MAX_BANKCODE) &&
			(branchCode >= MIN_BRANCHCODE && branchCode <= MAX_BRANCHCODE) &&
			(accountNumber >= MIN_ACCNO && accountNumber <= MAX_ACCNO)){
			_validAccNumber = 1;
		}
		else{
			_validAccNumber = 0;
		}

	};

	bool AccountNumber::isValid() const{
		return _validAccNumber;
	};

	void AccountNumber::display() const{

		if (_validAccNumber==1){
			cout << "Name: " << _name << ", Account number: " << _bankCode << "-"
				<< _branchCode << "-" << _accountNumber << endl;

		}
		else{
			cout << _name << " does not have a valid account number." << endl;
		}
	};
}