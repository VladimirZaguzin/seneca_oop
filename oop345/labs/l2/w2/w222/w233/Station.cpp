// Station.cpp
 #include <iostream>


 #include "Station.h"
 #include <string>
using namespace std;

namespace w2 {

	Station::Station() {
			name = "";
			StudPass = 0;
			AdultPass = 0;
			//cout << "C" <<endl;



		}

	void Station::set(const std::string& s, unsigned st, unsigned a) {
		//cout << "Setting....." << s <<" " << st << " " << a << endl;
		//cout << "name " <<name;
		name = s;
		StudPass = st;
		AdultPass = a;


	}

	//void Station::display() const{
	//cout << "Display" << "Name: " << name << " Studpass: " << StudPass << " AdultPass: " << AdultPass << endl;
   //}

	const std::string& Station::getName() const{
	
		return name;							
	
	}

	void Station::update(PassType type, int number){
		
		(type == 0)?StudPass += number:	AdultPass += number;		
	}

	unsigned Station::inStock(PassType type) const{
		
				
		return (type == 0)?StudPass:AdultPass;		
	
	}
	
		

}