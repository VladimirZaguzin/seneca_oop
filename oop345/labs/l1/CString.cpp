
#include "CString.h"

using namespace std;

//#pragma once
namespace w1{

	CString::CString(char* s){
		if (s == nullptr){
			str[0] = '\0';
		}
		else{
			strncpy(str, s, MAX);
			str[MAX] = '\0';
		}
	};

	void CString::display(std::ostream& os){
		os << str;
	}
 std::ostream& operator<<(std::ostream& os,CString& cs){
	static int count = 0; //local global var

	os <<count << " : ";
										   cs.display(os);
	os<<endl;
										   count++;
										return os;
}
}//namespace w1


