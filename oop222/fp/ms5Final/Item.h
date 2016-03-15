#ifndef SICT_ITEM_H_
#define SICT_ITEM_H_

#include "POS.h"
#include "PosIO.h"

namespace sict{

	class Item : public PosIO {
	private:
		char _sku[MAX_SKU_LEN + 1];
		char* _name;
		double _price;
		bool _taxes;
		int _quantity;

		void allocate(int strname);
		void deallocate();
	public:
		Item();
		Item(const char* _sku, const char* _name, double _price, bool _taxes = true);
		Item(const Item&);
		~Item();
		Item& operator=(const Item&);
		/*setters*/
		void sku(const char SKU[]);
		void price(double price);
		void name(const char* Name);
		void taxed(bool Tax);
		void quantity(int Quantity);
		/*getters*/
		const char* sku()const;
		const double price()const;
		const double cost()const;
		char* name()const;
		const bool taxed()const;
		const int quantity()const;
		bool isEmpty() const;
		/*operators*/
		bool operator==(const char* sku);
		int operator+=(int i);
		int operator-=(int i);


	};
	double operator+=(double& cost, Item& item);
	
	std::ostream& operator<<(std::ostream& ostr, const Item& itm);

	std::istream& operator>>(std::istream& is, Item& itm);

}
#endif