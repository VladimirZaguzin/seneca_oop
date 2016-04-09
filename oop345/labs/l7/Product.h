// Workshop 7 - STL Containers
// iProduct.h


#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>


namespace w7 {
    enum TaxType_e {NO_TAX, HST, PST};

    class iProduct {
		public:
			virtual double getCharge() const = 0;
			virtual void display(std::ostream&) const = 0;
    };

    class Product : public iProduct { 
//holds information about a product that consists of its product number and its cost
			
			int code;
			double price;
			
		public:
			
			Product(int c, double p) : code(c), price(p) { } //one line constractor
			
			double getCharge() const { //query returns the price chargable to the customer.
				return price;
			}

			void display (std::ostream& os) const{
				os << std::setw(10) << code << "   " << std::setprecision(2) << std::fixed << getCharge();
			}
    };
	
//holds additional information about the product's taxable status
    class ProductTaxible : public Product {
			int code;
			double price;
			TaxType_e tt;
		public:
			ProductTaxible(int c, double p, TaxType_e t) : Product(c,p), tt(t) {}
			
			double getCharge() const {
				double  p;
				switch ( tt ) {
					case HST: return Product::getCharge() * 1.13;
					case PST: return Product::getCharge() * 1.08;
				}
			}

			void display (std::ostream& os) const{
			   Product::display(os);
				switch ( tt ) {
					case HST: std::cout << " HST";
						break;
					case PST: std::cout << " PST";
						break;
				}
			}
    };


    std::ostream& operator<<(std::ostream& os, const iProduct& ref) {
        ref.display(os);
        return os;
    }

/*
The readProduct function receives a reference to the input file stream, 
reads the next record from the stream, 
allocates memory for the corresponding iProduct object, 
copies the record information into that object and 
returns its address to the caller function.
*/
    iProduct* readProduct(std::ifstream& is) {
        TaxType_e tc; //enum

        iProduct* returnValue = nullptr;
        std::string s;

		
		    int index = 0;
            int code = 0;
			double price = 0;
			double scale = 1;
			
			
        //skip this if statement if reached end of file
        if ( getline( is, s) ) {


		//looking for a strange character from Bill
            auto cr = s.find("\r");
            if(cr != std::string::npos) {
                std::cout << "found a CR at offset " << cr << "\n";
                s.erase( s.begin() + cr);
            }
        //process code
            //read one character at a time because it is more reliable
	
            while( index < s.size() && isdigit(s[index]) ) {
                //if substract value of '0'(30) you will get a number
                //if it is a digit * by 10 to keep track of thousands and substract 30 from a digit
                code = 10 * code + (s[index] - '0'); // this line calculates a number

                index++;
            }
            //skip white spaces
            while( index < s.size() && isspace(s[index]) ) {
                index++;
            }

            //process price without decimal points
            
			
            while( index < s.size() && isdigit(s[index]) ) {
                price = 10 * price + (s[index] - '0');
                index++;
            }

            //process price with decimal points
            if (index < s.size() && s[index] == '.') {
                index++; //skip .
            }
	
            while( index < s.size() && isdigit(s[index]) ) {
                price = 10 * price + (s[index] - '0'); //figure out what number is here
                index++;
                scale *= 0.1; // figure out number of hundreds (.1, .01, .001 etc.)
            }
            price *= scale;
           // std::cout << "price=" << price << "\n"; // price with decimal points

            //skip white spaces
            while( index < s.size() && isspace(s[index]) ) {
                index++;
            }

            //look for P or H
            if(index < s.size()) {
				if(s[index] == 'H'){
				tc = HST;	
				}
				else if(s[index] == 'P'){
				tc = PST;	
				}
				else{
				throw std::string("Unknown tax code '") + s[index] + "";	
				}
            }
            else {
                tc = NO_TAX;
            }

            //choose appropriate class for a product( HST, PST or NO_TAX)
            
				if(tc == HST or tc == PST){
					returnValue = new ProductTaxible(code,price,tc);
				}
				else{
					returnValue = new Product(code, price);
				}

        }

        return returnValue; // return nullptr
    }

}