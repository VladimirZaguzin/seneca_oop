#include <iostream>
#include <iomanip>


using namespace std;

#include "w1.h"
#include "checkout.h"
int main(){
	int iCost = 0;	// Selected item cost
	int iTotal = 0;
	cout << "SeneKEA Order Tool\n"
		<< "======================\n";

	// process user input
	while (iCost != 10){
		iCost = checkout();
		if (iCost == 0)
			cout << errMsg;
		else if (iCost == -1) {
			iTotal = 0;
			cout << cancelMsg;
		}
		else if (iCost == 10) {
			cout << "Total is $" << iTotal << endl;
			cout << printMsg;
		}
		else {
			cout << "Total increases by $" << iCost << endl;
			iTotal += iCost;
		}
	}
	return 0;
}