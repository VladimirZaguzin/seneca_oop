#ifndef SICT_CONTACT_H_
#define SICT_CONTACT_H_
#include "PhoneNumber.h"
namespace sict{
  class Contact{
    char _name[41];
    PhoneNumber* _pn;
    int _noPN;
    void setEmpty();

  public:

	  Contact& operator=(const Contact& C);
	  Contact(const Contact&);
	  Contact();
	  Contact(const char* name, int noPN);

    void read();
    void display()const;
    bool isEmpty()const;
  };
 
}

#endif