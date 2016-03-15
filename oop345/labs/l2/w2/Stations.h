#pragma once

#include <iostream>

#include "Station.h"

namespace w2 {

	class Stations{
		
	public:

			Stations(const char*dataFile);
			~Stations();
			Stations();

			void update();
			void restock();
			void report();
			
			std::string StationDataFile;

	private:

			int count;

			Station* stations;

	};
} //namespace w2
