//Stations.h
#pragma once
#include "Station.h"

namespace w2 {



class Stations{
	
		Station* stationTable;									
		int total_stations;
		char d;			
		std::string filename;						
	
	
		public:
		
		Stations();											
		Stations(const char*);								
		void update() const;								
		void restock() const;								
		void report() const;								
	    ~Stations();
		
	};

}