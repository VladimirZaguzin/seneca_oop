
//#include "Stations.h"
#include <fstream>
#include <iostream>	
#include <string>

namespace w2{

	/*stations.h*/

	/*
	#pragma once
	*/

	enum PassType{ PASS_STUDENT, PASS_ADULT, PASS_COUNT }; /*to generate arrays by computer, */

	class Stations{

	public:

		Stations(const char*dataFile);
		~Stations();

		void update();
		void restock();
		void report();
		std::string StationDataFile;
	private:
		int count;

		Station* stations;

	};
	/*stations.h*/





	/*stations.cpp*/
	void Stations::update(){
		for (int i = 0; i < count; i++){
			std::cout << "Station : " << stations[i].getName << std::endl;
			int s, a;

			std::cout << "Student Passes sold: ";
			std::cin >> s;
			std::cout << "Adult Passes sold: ";
			std::cin >> a;

			int numA = stations[i].inStock(PASS_ADULT);
			if (a < numA){
				stations[i].updage(PASS_ADULT, -a);
			}

			int numS = stations[i].inStock(PASS_STUDENT);
			if (s< numS){
				stations[i].updage(PASS_STUDENT, -s);
			}

		}
	};

	Stations::Stations(const char*dataFile){
		std::fstream is(dataFile, std::ios::in);
		
		
		//if(!is.is_open){
		
		if (!is){/*in case of a wrong filename*/
			std::cerr << "cannot open file >" << dataFile <<"<"<< std::endl;

			exit(2);

			//return;
		}
		/*right filename*/
		is >> count;
		std::cout << "Station count = " << count << std::endl;

		char c;
		is >> c;
		if (c == ';'){
			std::string s;
			getline(is, s, '\n');

			stations = new Station[count];
			for (int i = 0; i < count; i++){
				stations[i] = Station(is);
			}
		}

		else if (c != ';'){
			std::cerr << "Not our data file >" << dataFile << "< expected ';', found >" << c << '<' << std::endl;
			exit(3);
		}


		is.close();
	}


	void Stations::restock(){
		
		for (int i = 0; i < count; i++){

			std::cout << "Station : " << stations[i].getName << std::endl;
			int s, a;

			std::cout << "Student Passes added : ";
			std::cin >> s;

			std::cout << "Adult   Passes added : ";
			std::cin >> a;

			int numA = stations[i].inStock(PASS_ADULT);
			stations[i].updage(PASS_ADULT, +a);
			

			int numS = stations[i].inStock(PASS_STUDENT);
			stations[i].updage(PASS_STUDENT, +s);
			
		}

	};

	void Stations::report(){

		for (int s = 0; s < count; s++){
			std::cout << stations[s].getName() << " "
				<< stations[s].inStock[PASS_STUDENT]
				<< stations[s].inStock[PASS_ADULT] << std::endl;

		}

	};

	Stations::~Stations(){
		std::fstream os(StationDataFile);
		os << count << ';' << std::endl;
		for (int s = 0; s < count; s++){
			std::cout << stations[s]
		
		//delete[] stations;
	};
	/*stations.cpp*/







	/******************************************************************************/
	/*station.h*/

	/*
	#pragma once
	*/

	class Station{
	public:

		Station(std::fstream& is);

		Station();


	private:

		void report();
		void inStock();
		void write(std::fstream& os);

		void set(const std::string&, unsigned, unsigned); //- sets the instance variables to the values received in its parameters
		void update(PassType, int);// - updates the number of passes - sold if negative, added if positive
		unsigned inStock(PassType) const; //- returns the number of passes of the requested type
		const std::string& getName() const; //- returns a reference to a string object holding the name of the station

		std::string name;
		unsigned passCounts[PASS_COUNT];

	};
	/*station.h*/


	/*station.cpp*/
	void Station::report(){

		/*for (int s = 0; s < count; s++){
			std::cout << stations[s].getName() << " " 
					  << stations[s].inStock[PASS_STUDENT] 
					  << stations[s].inStock[PASS_ADULT] <<endl;

		}*/
		


	};

	void Station::write(std::fstream& os){
	
	}

	void Station::set(const std::string& n, unsigned s, unsigned a){
		name = n;
		passCounts[PASS_STUDENT] = s;
		passCounts[PASS_ADULT] = a;

	}

	void Station::update(PassType pt, int num){
		
		/*for (int s = 0; s < count; s++){
			std::cout << "Station: " << station[s].getName() << " \n";
			
			std::cout << " Student Passes sold : ";
			std::cin >> sales;
			stations[s].update(PASS_STUDENT, sales);

			std::cout << " Adult   Passes sold : ";
			std::cin >> sales;
			stations[s].update(PASS_ADULT, sales);

		


	};

}*/
	//unsigned Station::inStock(PassType) const;

	//const std::string& Station::getName() const;



	Station::Station(){

	};






	Station::Station(std::fstream& is){

		getline(is, name, ';');/*read line untile ; */
		std::cout << "name " << name << std::endl;/*print out name*/
		is >> passCounts[PASS_STUDENT];
		is >> passCounts[PASS_ADULT];

		std::string s;
		getline(is, s);

		std::cout << "Student count =" << passCounts[PASS_STUDENT] <<std::endl;
		std::cout << "Adult count =" << passCounts[PASS_ADULT] << std::endl;
		std::cout << std::endl;

	}
	/*station.cpp*/








}/*namespace w2*/
/******************************************************************************/








int main(int argc, char* argv[]) {
	std::cout << "\nCommand Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;
	if (argc != 2) {
		std::cerr << "\nIncorrect number of arguments\n";
		return 1;
	}
	w2::Stations stations(argv[1]);
	stations.update();
	stations.restock();
	stations.report();
	return 0;
}