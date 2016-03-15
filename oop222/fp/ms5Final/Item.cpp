#include "Item.h"

#include <iostream>
#include <cstring>
#include <string>

/* http://www.cplusplus.com/reference/new/ */
#include <new>
/***let is snow***let is snow***let is snow***/
namespace sict{
	Item::Item(){
		_name = (char*)0;
		_sku[0] = '\0';
		_price=-1;		
		_quantity=-1;
		_taxes=0;
	}


	Item::Item(const char* sku, const char* name, double price, bool taxes){
		_name = NULL;
		if (strlen(sku) <= MAX_SKU_LEN)
			strcpy(_sku, sku);
		else
			strcpy(_sku, "");
		allocate(strlen(name) + 1);
		strcpy(_name, name);
		_quantity = 0;
		_price = price;
		_taxes = taxes;
	}

	Item::Item(const Item& I){ // copy constractor
		_name = NULL;
		*this = I;
	}

	Item& Item::operator=(const Item& I){
		if (this != &I){
			_price = I._price;
			_taxes = I._taxes;
			_quantity = I._quantity;
			strcpy(_sku, I._sku);
			if (I._name){
				allocate(strlen(I._name) + 1);
				strcpy(_name, I._name);
				_name[strlen(I._name) + 1] = '\0';
			}
			else{
				deallocate();
			}
		}
		return *this;
	}

	/*allocate deallocate*/
	void Item::allocate(int Name){
		if (_name){
			deallocate();
		}
		_name = new (std::nothrow) char[Name]; //http://www.cplusplus.com/reference/new/nothrow/
	}

	void Item::deallocate(){
		delete[] _name;
		_name = (char*)0;	
	}

	Item::~Item(){
		deallocate();
	}
	/*!allocate deallocate*/

	/* member operator */
	bool Item::operator==(const char* sku){
		return (strcmp(sku, _sku) == 0);
	}

	int Item::operator+=(int i){
		return _quantity = _quantity + i;
	}

	int Item::operator-=(int i){
		return _quantity = _quantity - i;
	}
	/* !member operator */

	/*setters*/
	void Item::sku(const char SKU[]){
		strcpy(_sku, SKU);
	}
	void Item::price(double price){
		_price = price;
	}
	void Item::name(const char* Name){
		if (Name) {
			allocate(strlen(Name) + 1);
			strcpy(_name, Name);
		}
	}
	void Item::taxed(bool Tax){
		_taxes = Tax;
	}
	void Item::quantity(int Quantity){
		_quantity = Quantity;
	}
	/*!setters*/

	/*getters*/
	bool Item::isEmpty()const{
		return (_name == (char*)0);
	}

	const char* Item::sku()const{
		return _sku;
	}

	const double Item::price()const{
		return _price;
	}
	const double Item::cost()const{
		return (taxed()) ? price() + price()*TAX : price();
	}

	char* Item::name()const{
		return _name;
	}

	const bool Item::taxed()const{
		return _taxes;
	}

	const int Item::quantity()const{
		return _quantity;
	}
	/*!getters*/

	/*Operator +=*/
	double operator+=(double& cost, Item& item){
		return cost += item.cost() * item.quantity();
	}

	/*!Operator +=*/




	std::ostream& operator<<(std::ostream& ostr, const Item& itm){
		return (!itm.isEmpty()) ? itm.write(ostr, true) : ostr;
		//return itm.write(ostr, true);
	};

	std::istream& operator>>(std::istream& is, Item& itm){
		return itm.read(is);
	};


}