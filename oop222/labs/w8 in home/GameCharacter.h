#ifndef SICT_GAMECHARACTER_H__
#define SICT_GAMECHARACTER_H__
#include <iostream>
namespace sict{
	class GameCharacter{

	private:


	protected:
		int _strength;

	public:
		virtual bool isOut()const = 0;
		virtual int energy()const = 0;
		virtual int operator+=(int strength) = 0;
		virtual int operator-=(int strength) = 0;
		virtual std::ostream& display(std::ostream& os) const = 0;
		bool operator>(const GameCharacter& two);
		bool operator<(const GameCharacter& two);

	};
	std::ostream& operator<<(std::ostream& os, const GameCharacter& gc);
}

#endif