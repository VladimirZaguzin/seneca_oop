// Stations.cpp
 #include <iostream>
#include "Stations.h"
#include <iomanip>  
//#include "Station.h"
using namespace std;
 #include <fstream>

namespace w2 {

Stations::Stations(){
        total_stations = 0 ;
        stationTable = nullptr;                              
        filename = "";                                  
        d = ' ';                                
    }

Stations::Stations(const char* name) {
    filename = name; 
	cout << "Name of the file is " << filename << endl;
		
             
       
	fstream f(name);
	
     if (f.is_open()) {
     	f >> total_stations;
        f>>d;
     	cout << "Total Station " << total_stations <<endl;

     	stationTable = nullptr;
     	stationTable = new Station[total_stations];
     

for(int i=0; i < total_stations; i++) {                      
                    string stationname;
                    int StudPass;
                    int AdultPass;                                  
                    
                    
                    getline(f,stationname,d);                   
                    f >> StudPass;                         
                    f >> AdultPass;   
                    stationTable[i].set(stationname,StudPass,AdultPass);  
                      // stationTable[i].display();    

 }
     
     }

     else 
    	cout << "Not" << endl;

}





void Stations::update() const{
        
        std::cout << "\nPasses Sold :\n-------------";

        
        
        for(unsigned i=0 ; i < total_stations; i++){
        
            unsigned number = 0;              
            
            std::cout << stationTable[i].getName() << std::endl;     
          
            std::cout << " Student Passes sold : ";
            std::cin >> number;
         
            stationTable[i].update(student,(number*(-1)));           
        
            number = 0;
                  
            std::cout << " Adult   Passes sold : ";
            std::cin >> number;
           
            stationTable[i].update(adult,(number*(-1))); 
        //    stationTable[i].display();
                        
            
        }
        
    }

void Stations::restock() const{
        
        std::cout << "\nPasses Added :\n-------------";

        for(unsigned i=0 ; i < total_stations ; i++){
        
            unsigned number = 0;                
            std::cout << stationTable[i].getName() << std::endl;         
                
           
            std::cout << " Student Passes added : ";
            std::cin >> number;
            
            stationTable[i].update(student,number);                     
        
            number = 0;
                   
            std::cout << " Adult   Passes added : ";
            std::cin >> number;
                 
            stationTable[i].update(adult,number);  
                              
        }
        
    }


void Stations::report() const{
        
        std::cout << "\nPasses in Stock : Student Adult\n-------------------------------";
        
        for(unsigned i=0 ; i < total_stations; i++)
            std::cout << std::left << std::setw(18) << stationTable[i].getName() << std::right << std::setw(8) << stationTable[i].inStock(student) << std::setw(6) << stationTable[i].inStock(adult);
            
        std::cout << "\n-------------------------------" << std::endl;  
        
    }

Stations::~Stations(){
        
        std::ofstream file(filename);                   

        if (file.is_open()) {                   
            
            file << total_stations << d;                
            
            for(unsigned i = 0; i < total_stations ; i++){
            
                file << stationTable[i].getName() << d << stationTable[i].inStock(student) << " " << stationTable[i].inStock(adult);   //writes station name, delimiter character, number of student passes, space ,number of adult passes 
            
            }
            
          
            
        }
                                     
        
        if(stationTable){                                               
        
            delete [] stationTable;                                      
            stationTable = nullptr;                                      
        
        }
        
    }


}



