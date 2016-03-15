#ifndef SICT_NonPerishable_H_
#define SICT_NonPerishable_H_


#include "Item.h"
#include "ErrorMessage.h"
#include "Date.h"


using namespace std;

namespace sict{
  class NonPerishable:public Item{
  
  private:
    ErrorMessage _err;
	
  
  public:

    /*Pure virtual method implementations*/
	  std::fstream& save(std::fstream& file)const ;
	  std::fstream& load(std::fstream& file) ;
	  std::ostream& write(std::ostream& os, bool linear)const ;
	  std::istream& read(std::istream& is) ;

  };
}


#endif
