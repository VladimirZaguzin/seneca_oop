
#include "Stations.h"

#include <iostream>
#include <fstream>
#include <iomanip>

namespace w2 {

	Stations::Stations(){
		stations=nullptr;
		count =0;

	}

	
	Stations::Stations(const char*dataFile){
		std::fstream is(dataFile, std::ios::in);


		//if(!is.is_open){

		if (!is){/*in case of a wrong filename*/
			std::cerr << "cannot open file >" << dataFile << "<" << std::endl;

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

	Stations::~Stations(){
		std::fstream os(StationDataFile);
		os << count << ';' << std::endl;
	//	for (int s = 0; s < count; s++){

		//std::cout << stations[s]

		delete[] stations;
	
	}
	

	void Stations::update(){
	
		std::cout<<"Passes Sold :\n-------------\n";

		for (int i = 0; i < count; i++){
		
			std::cout << "Station : " << stations[i].getName() << std::endl;
			int s, a;

			std::cout << "Student Passes sold: ";
			std::cin >> s;
			std::cout << "Adult   Passes sold: ";
			std::cin >> a;

		std::cout<<std::endl;
			int numA = stations[i].inStock(PASS_ADULT);
			if (a < numA){
				stations[i].update(PASS_ADULT, -a);
			}

			int numS = stations[i].inStock(PASS_STUDENT);
			if (s< numS){
				stations[i].update(PASS_STUDENT, -s);
			}

		}
		
	}

	void Stations::restock(){

		std::cout<<"Passes Added :\n--------------\n";

		for (int i = 0; i < count; i++){

			std::cout << "Station : " << stations[i].getName() << std::endl;
			int s, a;

			std::cout << "Student Passes added : ";
			std::cin >> s;

			std::cout << "Adult   Passes added : ";
			std::cin >> a;

		std::cout<<std::endl;
			int numA = stations[i].inStock(PASS_ADULT);
			stations[i].update(PASS_ADULT, +a);


			int numS = stations[i].inStock(PASS_STUDENT);
			stations[i].update(PASS_STUDENT, +s);

		}

	};

	void Stations::report(){
		std::cout<< "Passes in Stock : Student Adult" << std::endl << "-------------------------------" << std::endl;
		for (int s = 0; s < count; s++){
			std::cout << std::setw(17)<<std::left<< stations[s].getName() << " "
				<< std::setw(7)<< stations[s].inStock(PASS_STUDENT) << " "
				<< std::setw(7)<< stations[s].inStock(PASS_ADULT) << std::endl;

		}

	};

}
