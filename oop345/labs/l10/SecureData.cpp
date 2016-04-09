#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <vector>
#include "SecureData.h"

namespace w10 {

    void converter(char* t, char key, int n, const Cryptor& c) {
        for (int i = 0; i < n; i++)
            t[i] = c(t[i], key);
    }

    SecureData::SecureData(const char* file, char key) {
        // open text file
        std::fstream input(file, std::ios::in);
        if (!input)
            throw std::string("\n***Failed to open file ") +
                  std::string(file) + std::string(" ***\n");

        // copy from file into memory
        nbytes = 0;
        input >> std::noskipws;
        while (input.good()) {
            char c;
            input >> c;
            nbytes++;
        }
        nbytes--;
        input.clear();
        input.seekg(0, std::ios::beg);
        text  = new char[nbytes + 1];

        int i = 0;
        while (input.good())
            input >> text[i++];
        text[--i] = '\0';
        std::cout << "\n" << nbytes << " bytes copied from text "
        << file << " into memory (null byte added)\n";
        encoded = false;

        // encode using key
        code(key);
        std::cout << "Data encrypted in memory\n";
    }

    SecureData::~SecureData() {
        delete [] text;
    }

    void SecureData::display(std::ostream& os) const {
        if (text && !encoded)
            os << text << std::endl;
        else if (encoded)
            throw std::string("\n***Data is encoded***\n");
        else
            throw std::string("\n***No data stored***\n");
    }

    void SecureData::code(char key) {
// ---------------------------------------------
    int NUM_THREAD;
        //NUM_THREAD = std::thread::hardware_concurrency(); //this one doesn't work on matrix 
	NUM_THREAD = 10;

	std::cout << "Amount of threads found: " << NUM_THREAD << " - " << nbytes <<std::endl;
        std::vector<std::thread> threads;

        
	int incr = nbytes / NUM_THREAD;
	
	std::cout << "After nbytes / NUM: " << incr << std::endl;
	
	int pos  = 0;
        int byte = incr;

        // launch execution of each thread
        for (int i = 0; i < NUM_THREAD; i++){
            threads.push_back(std::thread(converter, text + pos, key, byte, Cryptor()));
	    std::cout << "pushed thread" << std::endl;	
            pos += byte;
            if ((pos + incr) < nbytes)
                byte = incr;
            else
                byte = nbytes - pos;
	}
	std::cout << "Before joining" << std::endl;
 
	    for (int i = 0; i < NUM_THREAD; ++i)
                threads[i].join();
        

	std::cout << "Before converter func call" << std::endl;  
        converter(text, key, nbytes, Cryptor());
        encoded = !encoded;
//--------------------------------------------------
    }
    void SecureData::backup(const char* file) {
        if (!text)
            throw std::string("\n***No data stored***\n");
        else if (!encoded)
            throw std::string("\n***Data is not encoded***\n");
        else {




            // open binary file
            std::fstream ofile(file, std::ios::out | std::ios::binary);
            if(!ofile){
                throw std::string("\nFailed to open file") + std::string(file) + std::string("\n");
            }




            // write binary file here
            ofile.write(text, nbytes);
            ofile.close();



        }
    }

    //For restoration, your code deallocates the existing data, determines the number of bytes to be read,
    // allocates memory for them, and read the data from the file.
    void SecureData::restore(const char* file, char key) {

        
	    
	    
	// open  file
        std::fstream ofile(file, std::ios::in | std::ios::binary);
        if(!ofile){
            throw std::string("\nFailed to open file") + std::string(file) + std::string("\n");
        }
	
        
	
	
	
	// allocate memory 
        if (text){
		delete [] text;
		text = nullptr;
	}
        text  = new char[nbytes + 1];

        
	
	
	
	// read binary file 
        ofile.read(text, nbytes);
        ofile.close();

        std::cout << "\n" << nbytes + 1 << " bytes copied from binary file "
        << file << " into memory (null byte included)\n";
        encoded = true;

        
	
	
	// decode using key
        code(key);
	
        std::cout << "Data decrypted in memory\n\n";
    }

    std::ostream& operator<<(std::ostream& os, const SecureData& sd) {
        sd.display(os);
        return os;
    }
}
