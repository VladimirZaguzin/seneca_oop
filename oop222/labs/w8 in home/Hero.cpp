#include <cstring>
#include <iostream>
using namespace std;
#include "Hero.h"
namespace sict{

	Hero::Hero(){
		_strength = -1;
		_name[0] = '\0';
	}

	Hero::Hero(const char name[], int strength){
		strncpy(_name, name, 20);
		_strength = strength;
		_name[20] = '\0';
	}

	bool Hero::isOut()const{
		return _name[0] == '\0';
	}

	int Hero::energy()const{
	
		return (isOut()) ? 0 : _strength;
	}


	ostream& Hero::display(std::ostream& os) const{
		if (!isOut())
			os << _name << '(' << _strength << ')';
		return os;
	}

	int Hero::operator-=(int strength){
		return (strength > _strength) ? 0 : _strength - strength;
	}

	int Hero::operator+=(int strength){
		return  _strength + strength;
	}
}