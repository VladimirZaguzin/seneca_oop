#pragma once
#include <string>
#include <fstream>
#include <iostream>


namespace w2 {

	enum PassType{ PASS_STUDENT, PASS_ADULT, PASS_COUNT };

	class Station{
	
		private:
		
		

		unsigned passCounts[PASS_COUNT];

		std::string name;
	
		public:

		Station();

		Station(std::fstream& is);

		//void report();
		//void inStock();
		//void write(std::fstream& os);

		void set(const std::string&, unsigned, unsigned); //- sets the instance variables to the values received in its parameters
		void update(PassType, int);// - updates the number of passes - sold if negative, added if positive
		unsigned inStock(PassType) const; //- returns the number of passes of the requested type
		
		const std::string& getName() const; //- returns a reference to a string object holding the name of the station

		
		
	};
}