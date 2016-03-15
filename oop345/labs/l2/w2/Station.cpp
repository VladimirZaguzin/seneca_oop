#include "Station.h"

namespace w2 {

	Station::Station(){

	}

	Station::Station(std::fstream& is){

		getline(is, name, ';');/*read line untile ; */
		std::cout << "name " << name << std::endl;/*print out name*/
		is >> passCounts[PASS_STUDENT];
		is >> passCounts[PASS_ADULT];

		std::string s;
		getline(is, s);

		std::cout << "Student count =" << passCounts[PASS_STUDENT] << std::endl;
		std::cout << "Adult count =" << passCounts[PASS_ADULT] << std::endl;
		std::cout << std::endl;

	}


	void Station::set(const std::string& n, unsigned s, unsigned a){
		name = n;
		passCounts[PASS_STUDENT] = s;
		passCounts[PASS_ADULT] = a;

	}

	void Station::update(PassType pt, int number){
		passCounts[pt] += number;
	}

	unsigned Station::inStock(PassType pt) const{
		return passCounts[pt];
	}

	const std::string& Station::getName() const{
		return name;
	}
}