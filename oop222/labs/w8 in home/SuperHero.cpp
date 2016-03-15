#include <iomanip>
using namespace std;
#include "SuperHero.h"
namespace sict{

	SuperHero::SuperHero() :Hero(){
		
		_suppower = -1;
	}
	SuperHero::SuperHero(const char name[], int strength, int suppower) :
		Hero(name, strength){
		if (suppower < 0 || strength < 0){
			*this = SuperHero();
		}
		else{
		_suppower = suppower;
		}
	}

	int SuperHero ::energy()const{
		
		return Hero::energy()*_suppower;

	}

	void SuperHero ::operator*=(SuperHero& sh){
		if (_strength > sh._strength){
			_strength += sh._strength;
			sh._strength = -1;
			sh._name[0] = '\0';
			sh._suppower = -1;
		}
		else{
			sh._strength +=_strength;
			this->_strength = -1;
			this->_name[0] = '\0';
			this->_suppower = -1;
		}
	}
	ostream& SuperHero::display(std::ostream& os) const{
		if (!isOut()){
			os << "living superhero! " <<_name << "(" << _strength << ')';
		}
		else{
			os << "deceased superhero!"<<endl;
		}
		return os;
	}

	}





