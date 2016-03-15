#ifndef SICT_VALIDATE_H_
#define SICT_VALIDATE_H_
using namespace std;

#include<ctype.h>

namespace sict{

	template<typename T>
	bool validate(const T& minimum, const T& maximum, const T& testValue){
	
		return ((testValue >= minimum) && (maximum >= testValue)) ? true : false;
	
	};

	
	template<>
	bool validate(const char& minimum, const char& maximum, const char& testValue){
		return (toupper(testValue) >= toupper(minimum)) && (toupper(maximum) >= toupper(testValue)) ? true : false;
	};

}



#endif
