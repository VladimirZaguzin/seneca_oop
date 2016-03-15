#include <cstring>

#include <iomanip>
#include <ctime>
#include <new>
#include <string>
#include "PosApp.h"
using namespace std;
namespace sict{

	PosApp::PosApp(const PosApp&){

	}
	PosApp& PosApp::operator=(const PosApp& A){
		return *this;
	}


	PosApp::PosApp(const char* filename, const char* billfname){
		strcpy(_filename, filename);
		strcpy(_billfname, billfname);
		for (int i = 0; i < MAX_NO_ITEMS; i++)
			_items[i] = nullptr;
		_noOfItems = 0;
		loadRecs();
	}




	/*Menu prints the following menu and then asks the user to select one of
	the options of the menu.
	User can enter an integer between 1 and 6 to make the selection,
	if the value is outside of this range the selection will be set to -1.
	Before the user’s selection is returned, this function goes to new line.
	Note that this function does not print any error message.
	The keyboard is flushed and emptied after the entry.*/
	int PosApp::menu(){
		int num = -1;
		cout << "The OOPs Store" << endl;
		cout << "1- List items" << endl;
		cout << "2- Add Perishable item" << endl;
		cout << "3- Add Non-Perishable item" << endl;
		cout << "4- Update item quantity" << endl;
		cout << "5- Show Item" << endl;
		cout << "6- POS" << endl;
		cout << "0- exit program" << endl;
		cout << "> ";
		cin >> num;

		if (cin.fail()){
	//		cout << endl << "===Invalid Selection, try again.===" << endl << endl;
			cin.ignore(2000, '\n');
			cin.clear();
		}

		cin.ignore(2000, '\n');
		cin.clear();
		return num;
	}


	/*Loops through the _items pointer array up to “_noOfItems” and
	prints them in leaner format as follows:
	>Start
	 Row | SKU    | Item Name          | Price |TX |Qty |   Total |
	-----|--------|--------------------|-------|---|----|---------|
	1    | 1234   |Milk                | 3.99  | p | 7  |    27.93|
	2    | 2345   |Soap                | 23.45 | t | 2  |    53.00|
	3    | 3456   |Paper Cups          | 5.99  | t | 40 |   270.75|
	-----^--------^--------------------^-------^---^----^---------^
	Total Asset: $351.67

	>END
	
*/
	void PosApp::listItems()const{
		double total = 0;
		cout << endl;
		cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total |" << endl;
		cout << "-----|--------|--------------------|-------|---|----|---------|" << endl;
		for (int rawNum = 0; rawNum < _noOfItems; rawNum++){
			cout.fill(' ');
			cout << setw(4) << right << rawNum+1<< " | ";
			_items[rawNum]->write(cout, true);
			total += *_items[rawNum]; //dereference the pointer
			cout << endl;
		}
		cout << "-----^--------^--------------------^-------^---^----^---------^" << endl;
		cout << "Total Asset: $" << setprecision(2) << fixed << total << endl << endl;
	}


	/*
	Opens the data file for overwriting using an instance of fstream with 
	the filename kept in “_filename” and the ios::out flag. 
	Loops thought the “_items” array “_noOfItems” times and 
	write them into the file using their “save” method, 
	only if their quantity is more than zero. 
	Then it will close the data file and calls loadRecs() to have 
	the recent update of Items in the PosApp.
	*/
	void PosApp::saveRecs(){
		df.open(_filename, ios::out);
		for (int i = 0; i < _noOfItems; i++){
			 _items[i]->save(df);
		}
		df.close();

	}


	/*
	Works in two stages: 1- Opening the file:
	Opens the data file for read using an instance of fstream with
	the filename kept in “_filename” and the ios::in flag.
	If the opening fails (the file does not exist) it will clear the fstream,
	close it and then reopens it in write mode to create an empty file (ios::out)
	and exit the function.
	If the file opening does not fail, it goes to stage two.


	2- Reading the file: LoadRecs reads all the items kept in the file
	into the _items pointer array. Each record is read in two steps;
	first a single character is read to identify the type of the item
	(that will be either ‘P’ or ‘N’) and the next character (‘,’) is ignored.
	Depending on the first character being ‘P’ or ‘N’ a Perishable or NonPershiable object
	is created dynamically and the address is held in the _items pointer array.
	The using the “load” method of the item, the rest of the information is loaded into the object.
	Step “2” is repeated until end of file is reached.
	*/
	void PosApp::loadRecs(){
		char firstChar;
		df.open(_filename, ios::in);

		if (df.fail()){
			df.clear();
			df.close();
			df.open(_filename, ios::out);
			df.close();
		}
		else{
      while (!df.eof()){
        //delete _items[_noOfItems];
        df.get(firstChar);
		if (!df.fail()){    //eof()){
          if (firstChar == 'P'){
            df.ignore();
            _items[_noOfItems] = new Perishable();
            _items[_noOfItems]->load(df);
            _noOfItems++;
          }
          else if (firstChar == 'N'){
            df.ignore();
            _items[_noOfItems] = new NonPerishable();
            _items[_noOfItems]->load(df);
            _noOfItems++;
          }
          else{
            _items[_noOfItems] = nullptr;
          }
        }
			}
			df.close();
		}
	}

	/*updates quantity of an Item with the same sku as
	the one received from the argument of the function:
	This function will first prompt the user for an sku.
	Then it will call searchItem to find the item. If the item is not found,
	it will print “Not found!” and exit the function.
	If the item is found it will first display the item in non-linear format ,
	and then prompts the user for the number of items purchased.
	The received number is added it to the quantity of the item
	using the overloaded “operator +=”.
	Then it will save the records (saveRecs()) and print the message “Updated!”.
	Function should work exactly as follows:*/
	void PosApp::updateQty(){
		int qtyUp;
		 char SKU[2000];
		 cin >> SKU;
		 int i = searchItems(SKU);
		 if (i != -1){
			_items[i]->write(cout, false);
			cout << endl << "Please enter the number of purchased items: ";
			cin >> qtyUp;
			if (!cin.fail()){
				(*_items[i]) += qtyUp;
				saveRecs();
				cout << "Updated!" << endl;
				cout << endl;
				cin.clear();
			}	
		}
		 else{
			 cout << "Not found!" << endl;
			 cout << endl;
		 }
	}

	/*Loops through the _items array and compares them with the “sku” using the overloaded “operator==”.
	If there is a match, it will return the index of the found item,
	or “-1” if nothing is found.*/
	int PosApp::searchItems(const char* SKU)const{
		int retval = -1;
		for (int i = 0; i < _noOfItems && retval == -1; i++){
			if (*_items[i] == SKU)
				retval = i;
		}
		
		return retval;
	}


	/*Depending of the value of the “isPershable” argument,
	it will dynamically create a Perishable or NonPerishable Item.
	Then it will receive the item information from the user using cin.
	If anything goes wrong, (cin fails) it will clear cin and flush the keyboard,
	and then display the item using cout to show the error.
	If the Item is received successfully from the user,
	it will add it to the “_items” pointer array and add one to “_onOfItems”.
	Then it will save the records into the file and print “Item Added.”.*/
void PosApp::addItem(bool isPerishable){
	if (isPerishable){
		Perishable* p = new Perishable();
		p->read(cin);
		if (cin.fail()) {
			cout << p;
			delete p;
		}
		else {
			_items[_noOfItems] = p;
			_noOfItems++;
			saveRecs();
			cout << "Item added." << endl << endl;
		}
		p = nullptr;
	}
	else {
		NonPerishable* n = new NonPerishable();
		n->read(cin);
		if (cin.fail()) {
			cout << n;
			delete n;
		}
		else {
			_items[_noOfItems] = n;
			_noOfItems++;
			saveRecs();
			cout << "Item added."<<endl << endl;
		}
		n = nullptr;
	}
}

/*
>Start
v--------------------------------------------------------v
| 2015/12/01, 11:30                                      |
| SKU    | Item Name          | Price |TX |Qty | Total   |
|--------|--------------------|-------|---|----|---------|
| 1234   |Milk                | 3.99  |  p|   1|     3.99|
| 2345   |Soap                | 23.45 | t |   1|    26.50|
| 3456   |Paper Cups          | 5.99  | t |   1|     6.77|
| 2345   |Soap                | 23.45 | t |   1|    26.50|
^--------^--------------------^-------^---^----^---------^
Total $63.76
*/

/*
Opens the bill file for reading using an instance of fstream with the filename kept in “_billfname” and the ios::in flag.
This file has the same format of the “_datafile”.
Read the items one by one, the same way you did in loadRecs method.
But instead of adding the items to the _items array, print them in linear format and immediately delete what you printed.
Continue until you hit the end of file.
When done, close the file, and reopen it for overwrite and truncating  using (ios::out|ios::trunc) to delete its content and close it again.
Like this, any bill that is printed will be deleted in the file. (You cannot print a bill twice)

*/
void PosApp::showBill(){
	double total = 0;
	cout.fill(' ');
	char first = ' ';
	Item* tmp;

	fstream bill(_billfname, ios::in);

	time_t rawtime;
	tm* timeinfo;

	rawtime = time(0);
	timeinfo = localtime(&rawtime);

	if (bill.fail()){
		bill.clear();
		bill.close();
		bill.open(_billfname, ios::out);
		bill.close();
	}
	else{
		cout << "v--------------------------------------------------------v" << endl;
	
		cout << "| "
			<< left << 1900 + timeinfo->tm_year
			<< left << '/' << left << 1 + timeinfo->tm_mon
			<< left << '/' << timeinfo->tm_mday
			<< left << ", " << left << timeinfo->tm_hour
			<< left << ':' << left << setprecision(2) << 1 + timeinfo->tm_min
			<< left << "                                      ";

		if (timeinfo->tm_mon < 10) cout << " ";
		if (timeinfo->tm_mday < 10) cout << " ";
		if (timeinfo->tm_min < 10) cout << " ";

		(timeinfo->tm_hour < 10) ? cout << " |" << endl : cout << "|" << endl;
		cout << "| SKU    | Item Name          | Price |TX |Qty |   Total |" << endl;
		cout << "|--------|--------------------|-------|---|----|---------|" << endl;



		while (!bill.eof() || !bill.fail()){
				bill.get(first);
				bill.ignore(1);
				if (!bill.eof()){
					cout << "| ";
					if (first == 'P'){
						tmp = new Perishable();
						tmp->load(bill);
						tmp->write(cout, true);
						total += tmp->cost();
					}
					else if (first == 'N'){
						tmp = new NonPerishable();
						tmp->load(bill);
						tmp->write(cout, true);
						total += tmp->cost();
					}				
			//		_noOfItems++;
					cout << endl;
				}
		}
				cout << "^--------^--------------------^-------^---^----^---------^" << endl;
				cout << "Total: $" << setprecision(2) << fixed << total << endl;
				cout << endl;

				bill.clear();
				bill.close();
				bill.open(_billfname, ios::out);
				bill.close();
		}
	}
	/*
	Adds an item to the bill file, (name kept in “_billfname”) with quantity of 1.
	First copy the quantity of the Item referred to by the argument I,
	into a local variable called qty for future use. 
	Then set the quantity if I to 1. 
	Open the bill file for appending using an instance of fstream with the filename kept in “_billfname” and 
	the (ios::out | ios::app)flag. Like this if the file does not exist, it will create it. 
	Then save the Item referred to by I using the “save” method. 
	Then reduce the qty value by one, but do go bellow zero. 
	Finally set the quantity of I to qty and save the Records (saveRecs()) to update the datafile.
	*/
	void PosApp::addToBill(Item& I){
		int qty;
		qty = I.quantity();
		I.quantity(1);

		df.open(_billfname, ios::out | ios::app);
		if (qty > 0){
			qty--;
}
		I.save(df);
		I.quantity(qty);
		

		df.close();
		saveRecs();

	}


	/*
	while not done 
		Ask for sku 
		If sku is an empty string 
			show bill and the function is done 
		Search for sku in the items 
		if found 
			print the name only 
			add it to the bill 
		if not found 
			print “Not found!” 
	End while
	*/
	void PosApp::POS(){
		string inp_sku;
		char *cstr = new char[MAX_SKU_LEN +1];
		do{
			cout << "Sku: ";
			getline(cin, inp_sku);
			
			if (inp_sku.empty()){
				showBill();
			}
			else{
				strcpy(cstr, inp_sku.c_str());
				
				if (searchItems(cstr) != -1){

					if (_items[searchItems(cstr)]->quantity() > 0){
						cout << "v------------------->" << endl;
						cout << "| " << _items[searchItems(cstr)]->name() << endl;
						cout << "^------------------->"<< endl;
						addToBill(*_items[searchItems(cstr)]);
					}
					else{
						cout << "Not found!" << endl;
					};
				}
				else{	
					cout << "Not found!" << endl;
				};
			}
		} while (!inp_sku.empty());
	delete[] cstr;
	}

	/*
	User selects 1: Call listItems.
	User selects 2: Call addItem.
	User selects 3: Call addItem.
	User selects 4: Call updateQty.
	User selects 5: Prompt the user for receiving sku.
	get the sku and searchItems() for it.
	if found display it in non-linear format if no found display “Not found!”.
	User selects 6: Call POS.
	User selects 0: Exit program printing “Goodbye!”
	*/
	void PosApp::run(){
		int returnVal = 1;
		char SKU[MAX_SKU_LEN+1];
		while (returnVal != 0){
			returnVal = menu();
			switch (returnVal)
			{
			case 1:
				listItems();
				break;
			case 2:
				cout << endl;
				addItem(true);
				break;
			case 3:
				cout << endl;
				addItem(false);
				break;
			case 4:
				cout << endl << "Please enter the SKU: ";
				updateQty();
				
				
				
				break;
			case 5:
				cout <<endl<< "Please enter the SKU: ";
				cin >> SKU;
				if (searchItems(SKU) != -1){
					cout <<"v-----------------------------------v" << endl;
					_items[searchItems(SKU)]->write(cout, false);
					cout << "^-----------------------------------^"  << endl<< endl;
					
				}
				else{
					cout << "Not found!" << endl;
					cout << endl;
				}
				break;
			case 6:
				cout << endl;
				POS();
				break;
			case 0:
				cout<< endl << "Goodbye!!" << endl;
				break;
			default:
				cout << endl<< "===Invalid Selection, try again.===" << endl << endl;
			}
		}
	
	}









	/*
	NEXT TIME PLZ GIVE FULL EXAMPLE OF OUTPUT	
	IT TAKES TOO MUCH TIME TO PUT ALL SPACES, AND NEW LINES, AND SMALL/CAP LETTERS WITHOUT SEEN FULL PICTURE
	PLZ MAKE A NOTES ABOUT EVERY REMOVED OR ADDED SPACE!
	*/



}