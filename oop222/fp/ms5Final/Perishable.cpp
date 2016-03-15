
#include "Perishable.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>

namespace sict{
  // constructor
  Perishable::Perishable() : Item() {
    _expiry.dateOnly(true);
  }


  // Setters and getters 
  const Date& Perishable::expiry()const{
    return _expiry;
  }

  void Perishable::expiry(const Date &value){
    _expiry = value;
  }


  std::fstream& Perishable::save(std::fstream& file)const{
    /*P,1234,4L Milk,3.99,0,2,2015/12/10<Newline>*/
    /*sku, name, price, taxed, quantity, expiry date */
    file << "P," << sku() << "," << name() << "," << price() << ',' << taxed() << "," << quantity() << ",";
    _expiry.write(file);
    file << endl;
    return file;
  }

  std::fstream& Perishable::load(std::fstream& file){
    /*1234,4L Milk,3.99,0,2,2015/12/10<Newline>*/
    /*sku, name, price, taxed, quantity, expiry date */

    char isku[MAX_SKU_LEN];

    char iname[2000];
    double iprice;
    bool itaxed;
    int iquantity;
    Date idate;
    idate.dateOnly(true);

    file.getline(isku, MAX_SKU_LEN, ',');
    sku(isku);
    file.getline(iname, 2000, ',');
    name(iname);
    file >> iprice;
    price(iprice);
    file.ignore();
    file >> itaxed;
    taxed(itaxed);
    file.ignore();
    file >> iquantity;
    quantity(iquantity);
    file.ignore();
    file >> idate;
    expiry(idate);
    file.ignore();
    return file;
  }

  std::ostream&  Perishable::write(std::ostream& os, bool linear)const{
    /*1234   |4L Milk             |   3.99|  p|   2|     7.98|*/

    /*
     Sku:           left justified in MAX_SKU_LEN characters
     Name:          left justified 20 characters wide
     Price:                 (not the price) right justified, 2 digits after decimal point 7 chars wide
     Taxed:         “ tp” for taxed, “  p” for not taxed (3 chars wide)
     Quantity:      right justified 4 characters wide
     Cost:       total cost, considering quantity and tax; same format as price, 9 chars wide
     NO NEW LINE


     cost() == (taxed()) ? price() + price()*TAX : price();
     */
    if (_err.isClear()){
      if (linear){
	os.fill(' ');
	os << setw(MAX_SKU_LEN) << left << sku() << "|";
	os << setw(20) << left << name() << "|";
		os << setw(7) << fixed << right << setprecision(2) << price() << "|";

	(taxed()) ? os << setw(3) << fixed << right << "tp" << "|" : os << setw(3) << fixed << right << "p" << "|";
	os << setw(4) << right << quantity() << "|";
	os << setw(9) << fixed << right << setprecision(2) << cost()*quantity() << "|";

	//os << endl;
      }
      else{
	/* Name:
	   4L Milk
	   Sku: 1234
	   Price: 3.99
	   Price after tax: 4.51
	   Quantity: 2
	   Total Cost: 9.02
	   Expiry date: 2015/12/10 <Newline>

	   Or if not taxed:

	   Name:
	   4L Milk
	   Sku: 1234
	   Price: 3.99
	   Price after tax: N/A
	   Quantity: 2
	   Total Cost: 7.98
	   Expiry date: 2015/12/10 <Newline>
	   */
	/*      os << "Name:" << endl << name() << endl << "Sku: " << sku() << endl << "Price: " << price() << endl << "Price after tax: ";
	  (taxed()) ? os << cost() << endl : os << "N/A" << endl;
	  os << "Quantity: " << quantity() << endl << "Total Cost: " << quantity()  *  cost() << endl << "Expiry date: " << expiry() << endl;*/

	cout << "Name:" << endl << name() << endl; // thx for your code and this funny part of it
	cout << "Sku: " << sku() << endl;
	cout << "Price: " << price() << endl;
	cout << "Price after tax: ";
	(taxed()) ? os << cost() << endl : os << "N/A" << endl;
	cout << "Quantity: " << quantity() << endl;
	cout << "Total Cost: " << quantity()  *  cost() << endl;
	cout << "Expiry date: " << expiry() << endl;

      }
    }
    else{
      os << _err;
    }
    return os;
  }



  std::istream& Perishable::read(std::istream& istr){

    char buf[1000];
    int ibuf;
    double dbuf;
    char ctax;
    //Date idate;
    //       idate.dateOnly(true);
    _err.clear();
    cout << "Perishable Item Entry: " << endl;
    cout << "Sku: ";
    istr.getline(buf, MAX_SKU_LEN, '\n');
    sku(buf);
    cout << "Name:" << endl;
    istr.getline(buf, 20, '\n');
    name(buf);
    cout << "Price: ";
    istr >> dbuf;
    if (!istr.fail()) {
      price(dbuf);
      cout << "Taxed: ";
      istr >> ctax;
		  if (ctax == 'y'||ctax=='Y'){
		taxed(1);
		  }
		  else if (ctax == 'n'||ctax=='N'){
		taxed(0);
		  }
		  else{
		istr.setstate(ios::failbit);
		  }
      if (!istr.fail()) {
		cout << "Quantity: ";
		istr >> ibuf;
		if (!istr.fail()) {
		  quantity(ibuf);
		  cout << "Expiry date (YYYY/MM/DD): "; //THIS IS OUTPUT FROM MS4 Expiry date (YYYY/MM/DD) : 2015/12/10<ENTER> AND THERE IS SPACE BETWEEN (YYYY/MM/DD) AND : . BUT IN MS5 SUBMITION THERE IS NOT. RLY?!

		  istr >> _expiry;
		  //idate.read(istr);
		  if (_expiry.bad()){
			switch (_expiry.errCode()) {
			case CIN_FAILED:
			  _err.message("Invalid Date Entry");
			  istr.setstate(ios::failbit);
			  break;
			case YEAR_ERROR:
			  _err.message("Invalid Year in Date Entry");
			  istr.setstate(ios::failbit);
			  break;
			case MON_ERROR:
			  _err.message("Invalid Month in Date Entry");
			  istr.setstate(ios::failbit);
			  break;
			case DAY_ERROR:
			  _err.message("Invalid Day in Date Entry");
			  istr.setstate(ios::failbit);
			  break;
			}
			istr.setstate(ios::failbit);
		  }
	}
	else{
	  _err.message("Invalid Quantity Entry");
	}
      }
      else {
	_err.message("Invalid Taxed Entry, (y)es or (n)o");
      }
    }
    else {
      _err.message("Invalid Price Entry");
    }
    return istr;
  }




}
