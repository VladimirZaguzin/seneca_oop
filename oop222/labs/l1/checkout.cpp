#include <iostream>
#include <iomanip>

using namespace std;


int checkout(){

	int iSelection = 0;			//storage of the user response
	int iPrice = 0;
	cout << '\n';
	cout << "Please select from the following options :\n";
	cout << " 1 Shelf unit $2\n";
	cout << " 2 Desk $4\n";
	cout << " 3 Bed $4\n";
	cout << " 4 Chair $2\n";
	cout << " 5 Pay\n";
	cout << " 6 Cancel\n";

	cin >> iSelection;
	if ((iSelection > 0) && (iSelection < 7)){//if user response is valid
		if (iSelection == 1 || iSelection == 4)
			iPrice = 2;
		else if (iSelection < 5)
			iPrice = 4;
		else if (iSelection == 5)
			iPrice = 10;
		else
			iPrice = -1;
		cout << "Thank you\n";
	}
	else
		cout << "Incorrect entry\n";

	return iPrice;
}