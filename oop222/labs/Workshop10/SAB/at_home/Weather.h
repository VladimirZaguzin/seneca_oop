#ifndef SICT_WEATHER_H_
#define SICT_WEATHER_H_
using namespace std;



namespace sict{
	class Weather {
	private:
		float _hitemp;

	public:
		Weather(float hiTemp);

		bool operator==(const Weather& D)const;
		bool operator!=(const Weather& D)const;
		bool operator<(const Weather& D)const;
		bool operator>(const Weather& D)const;
		bool operator<=(const Weather& D)const;
		bool operator>=(const Weather& D)const;

	};
}



#endif
