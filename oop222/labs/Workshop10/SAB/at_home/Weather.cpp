#include "Weather.h"

namespace sict{

	Weather::Weather(float hiTemp){
		_hitemp = hiTemp;
	};
 

	bool Weather::operator>=(const Weather& D)const{
		return (this->_hitemp >= D._hitemp) ? true : false;
	}

	bool Weather::operator<=(const Weather& D)const{
		return (this->_hitemp <= D._hitemp) ? true : false;
	}

	bool Weather::operator>(const Weather& D)const{
		return (this->_hitemp > D._hitemp) ? true : false;
	}

	bool Weather::operator<(const Weather& D)const{
		return (this->_hitemp < D._hitemp) ? true : false;
	}

	bool Weather::operator!=(const Weather& D)const{
		return (this->_hitemp != D._hitemp) ? true : false;
	}

	bool Weather::operator==(const Weather& D)const{
		return (this->_hitemp == D._hitemp) ? true : false;
	}

}

