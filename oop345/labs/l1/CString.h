#pragma once


#include <iostream>
#include <cstring> //strncpy

namespace w1{



#define MAX 3 
	class CString{

		char str[MAX + 1];

	public:

		CString(char* s);
		void display(std::ostream& os);

	};
	std::ostream& operator << (std::ostream&, CString&);

}
