#include <iostream>
using namespace std;
#include "GameCharacter.h"

namespace sict{


	bool GameCharacter::operator>(const GameCharacter& two){
		return (energy() > two.energy()) ? true : false ;
	}

	bool GameCharacter::operator<(const GameCharacter& two){
		return (energy() < two.energy()) ? true : false ;
	}


	std::ostream& operator<<(std::ostream& os, const GameCharacter& gc){
		gc.display(os);
		return os;
	}



}