#ifndef SICT_Perishable_H_
#define SICT_Perishable_H_


#include "Item.h"
#include "ErrorMessage.h"
#include "Date.h"


using namespace std;

namespace sict{
  class Perishable:public Item{
  private:
    ErrorMessage _err;
	Date _expiry;
  
  public:
    /*default constructor*/
     Perishable();

    /*Pure virtual method implementations*/
	 std::fstream& save(std::fstream& file)const;
	 std::fstream& load(std::fstream& file);
	 std::ostream& write(std::ostream& os, bool linear)const;
	 std::istream& read(std::istream& ist);


     /* Public Accessors */
     const Date& expiry()const;
     void expiry(const Date &value);


  };
}


#endif
