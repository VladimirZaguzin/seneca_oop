#include "process.h"
#include "CString.h"

using namespace std;


int main(int argc, char* argv[], char* env[]){

/*
	cout << "argc = " << argc << endl;

	for (int arg = 0; arg < argc; arg++){
		cout << "argv[" << arg << "]= -->" << argv[arg] << "<--" << endl;

	}
	*/

	cout << "Command line :";
	for (int arg = 0; arg < argc; arg++){
		cout << argv[arg] << ' ';
	}
	cout << endl;

     if (argc == 1){
		cerr << "Insufficient number of arguments (min 1)" << endl;
	}
	else{
		if (argc > 1 && argc <= MAX){
			cout << "Maximum number of characters stored :" << MAX << endl;
			
			for (int arg = 1; arg < argc; arg++){
				process(argv[arg]);
			}
		}               
	}
	


	return 0;
}
