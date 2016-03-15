#include <cstring>
#include <new>
#include <iomanip>
#include "PosApp.h"
using namespace std;
namespace oop244{
 
  // copy constructor and assignment operator
   PosApp::PosApp(const PosApp&){

   }
   PosApp& PosApp::operator=(const PosApp& A){
      return *this;
   }

  // constructor 
  // copies filename to _filename
  // sets all the _items to null
  // sets _noOfItems to null
  // loads the Records
   PosApp::PosApp(const char* filename){
      strcpy(_filename, filename);
      for (int i = 0; i < MAX_NO_RECS; i++)
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
     cout << "0 - exit program" << endl;
     cin >> num;

	 
	 switch (num){
     case 1 :
        cout << "1 - List items" << endl;
        break;
     case 2 :
        cout << "2 - Add Non-food item Item" << endl;
        break;
     case 3 :
        cout << "3 - Add Perishable item" << endl;
        break;
     case 4 : 
        cout << "4 - Update item quantity" << endl;
        break;
	 case 5:
		 cout << "5- Show Item" << endl;
		 break;
	 case 6:
		 cout << "6- POS" << endl;
		 break;
     case 0 :
        cout << "0 - exit program" << endl;
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
     cout << "   Row | SKU    | Item Name          | Price |TX |Qty |   Total |" << endl;
     cout << "-----|--------|--------------------|-------|---|----|---------|" << endl;
     for (int rawNum = 0; rawNum < _noOfItems; rawNum++){
        cout.fill(' ');
        cout << setw(4) << right << rawNum;
        cout << " | ";
        _items[rawNum]->display(cout, true);
        total += *_items[rawNum]; //dereference the pointer
        cout << endl;
      }
     cout << "-----^--------^--------------------^-------^---^----^---------^ " << endl;
     cout << "Total Asset: $" << setprecision(2) << fixed << total << endl;
}


  // opens the file for writing
  // stores the items in the file
  // closes the file
  void PosApp::saveRecs(){
     datafile.open(_filename);
     for (int i = 0; i < _noOfItems; i++){
        datafile << _items[i];
     }
     datafile.close();

  }


  /*Works in two stages: 1- Opening the file: 
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
  Step “2” is repeated until end of file is reached.*/

  void PosApp::loadRecs(){
     int readIndex = 0;
     char firstChar;
     datafile.open(_filename, ios::in);
 
     if (datafile.fail()){
        datafile.clear();
        datafile.close();
        datafile.open(_filename, ios::out);
        datafile.close();
     }
     else{
        while (!datafile.eof()){
           if (_items[readIndex] != nullptr){
              delete _items[readIndex];
              _items[readIndex] = nullptr;
           }
           datafile.get(firstChar);
           if (firstChar == 'P'){
              datafile.ignore();
              _items[readIndex] = new Perishable();
              _items[readIndex]->load(datafile);
              readIndex++;
           }
           else if (firstChar == 'N'){
              datafile.ignore();
              _items[readIndex] = new NFI();
              _items[readIndex]->load(datafile);
              readIndex++;
           }
        }
        _noOfItems = readIndex;
        datafile.close();
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
  void PosApp::updateQty(const char* SKU){
     int qtyPurchased;
     for (int i = 0; i < _noOfItems; i++){
        if (*_items[i] == SKU){
           _items[i]->display(cout, false);
           cout << "Please enter the number of purchased items: ";
           cin >> qtyPurchased;
           if (cin.fail()){
              cout << "Invalid Quantity value!" << endl;
           }
           else {
              if (qtyPurchased <= (_items[i]->qtyNeeded() - _items[i]->quantity())){
                 *_items[i] += qtyPurchased;
              }
              else {
                 cout << "Too much items, only " << _items[i]->qtyNeeded() << "is needed, please return the extra " << _items[i]->quantity() - _items[i]->qtyNeeded() << "items." << endl;
              }
           }
           saveRecs();
           cout << "Updated!" << endl;
              cin.clear();
        }
     }

}
  
  /*Loops through the _items array and compares them with the “sku” using the overloaded “operator==”. 
  If there is a match, it will return the index of the found item,
  or “-1” if nothing is found.*/
  int PosApp::SearchItems(const char* SKU)const{
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
        p->conInput(cin);
        if (cin.fail()) {
           cin.clear();
           p->display(cout, false);
           delete p;
        }
        else {
           _items[_noOfItems] = p;
           _noOfItems++;
           saveRecs();
           cout << "Records saveds successfully!" << endl;
        }
        p = nullptr;
     }
     else {
        NFI* n = new NFI();
        n->conInput(cin);
        if (cin.fail()) {
           cin.clear();
           n->display(cout, false);
           delete n;
        }
        else {
           _items[_noOfItems] = n;
           _noOfItems++;
           saveRecs();
           cout << "Records saveds successfully!" << endl;
        }
        n = nullptr;
     }
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
  int PosApp::run(){
     int returnVal = 1;
     char SKU[MAX_SKU_LEN];
     while (returnVal != 0){
        returnVal = menu();
        switch (returnVal)
        {
        case 1:
           listItems();
           break;
        case 2:
           addItem(false);
           break;
        case 3:
           addItem(true);
           break;
        case 4:
           cout << "Please enter the SKU: ";
           cin >> SKU;
           updateQty(SKU);
           break;



        case 0:
           cout << "Goodbye!!" << endl;
           break;
        default:
           cout << "===Invalid Selection, try again.===";
        }
     }
     return 0;
  } 
}