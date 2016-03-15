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

	void AccountNumber::displayName() const{
	//	if (_validAccNumber == 1){
			cout << "Name: " << _name;
	//	};
	};

	void AccountNumber::displayNumber() const {
	//	if (_validAccNumber == 1){
			cout << "Account number: " << _bankCode << "-"
				<< _branchCode << "-" << _accountNumber;
	//	};
	};
	void AccountNumber::display(bool displayName, bool displayNumber) {

		if ( displayName == 0 ){
			cout << "I am wrong!" << endl;
			//AccountNumber::displayNumber();
			//cout << endl;
		}
		else if (displayName == 1 && displayNumber == 0) {
			cout << "Name is true, number is wrong!" << end;
			//AccountNumber::displayName();
			//cout << endl;
		} 
		else if (displayName == 1 && displayNumber == 1) {
			cout << "yeeeeeeeeah" << endl;
			//AccountNumber::displayName();
			//cout << endl;
			//AccountNumber::displayNumber();
			//cout << endl;
		}
		
	};
}
