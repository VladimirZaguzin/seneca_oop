#ifndef SICT_POSAPP_H__
#define SICT_POSAPP_H__
#include "Perishable.h"
#include "NonPerishable.h"
namespace sict{
  class PosApp{
   
	char _filename[128];
    char _billfname[128];
    Item* _items[MAX_NO_ITEMS];
    int _noOfItems;



	int menu();
    void loadRecs();
    void saveRecs();
    int searchItems(const char* sku)const;
	void updateQty();
    void addItem(bool isPerishable);
    void listItems()const;
    void showBill();
    void addToBill(Item& I);
    void POS();

	std::fstream df; //Opening the file: Opens the data file for read using an instance of fstream with the filename kept in �_filename� and the ios::in flag. ??????????????



  public:   
    // prevent copying and assignment here!
    PosApp(const char* filename, const char* billfname);
    void run();
	PosApp(const PosApp&);
	PosApp& operator=(const PosApp& A);
  };
}
#endif
