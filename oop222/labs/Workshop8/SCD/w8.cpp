#include <iostream>
#include "Bus.h"
#include "Truck.h"

int main()
{
	// part 1 code
	Bus cityBus39(20, 78);
	Truck pickUp(30, true);
	move(cityBus39);
	move(pickUp);
	show(cityBus39);
	show(pickUp);


	/* part 2 code
	 uncomment after you have completed 
	 part 1
	
	Bus cityBus144;
	Truck pickUpAA4;
	std::cin >> cityBus144 >> pickUpAA4;
	std::cout << cityBus144 << pickUpAA4;
	*/
    
    return 0;
}