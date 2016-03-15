// #include "Stations.h"
namespace w2 {

enum PassType{ student, adult};	

class Station {
	private:
		std::string name;
		unsigned int StudPass;
		unsigned int AdultPass; 
	public:
		Station();
		void set(const std::string&, unsigned, unsigned);
		void display() const;
		void update(PassType, int);
		unsigned inStock(PassType) const;
		const std::string& getName() const;
};

}