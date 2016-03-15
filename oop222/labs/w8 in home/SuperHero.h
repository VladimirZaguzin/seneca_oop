#include <iostream>
using namespace std;
#include "Hero.h"
namespace sict{
  class SuperHero : public Hero {

  private:
	  int _suppower;
  public:
	  SuperHero();
	  SuperHero(const char name[], int strength, int suppower);
	  int energy()const;
	  void operator*=(SuperHero& sh);

	  std::ostream& display(std::ostream& os) const;


  };
}
