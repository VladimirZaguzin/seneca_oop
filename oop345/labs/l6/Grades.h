#pragma once 
#include <iomanip>
#include <fstream>
#include <string>

class Grades{
	size_t _size;
	int* _numbers;
	double* _grades;

public:
	Grades(const char* filename) :_size(0), _numbers(nullptr), _grades(nullptr)
	{
		std::fstream fs(filename);
		if (!fs)
			throw std::string("*** failed to open file ") + std::string(filename) + std::string(" ***");
		std::string line;
		size_t count = 0;

		while (getline(fs, line))
		{
			count++;
		}
		fs.clear();
		fs.seekg(0, std::ios::beg);
    if (_numbers){
      delete[] _numbers;
    }
    if(_grades){
      delete[] _grades;
    }
    _numbers=nullptr;
    _grades=nullptr;
		_numbers = new (std::nothrow) int[count];
		_grades = new (std::nothrow) double[count];
		_size = count;

		for (size_t i = 0; i < count; i++)
		{
			fs >> _numbers[i];
			fs >> _grades[i];

		}
		fs.close();
	}
	virtual ~Grades()
	{
		delete[] _numbers;
		delete[] _grades;
	}

	void displayGrades(std::ostream& os, const char*(*express)(double)) const
	{
		for (size_t i = 0; i < _size; i++)
		{
			os << _numbers[i] << ' ' << std::fixed << std::setprecision(2) << _grades[i] << ' ' << express(_grades[i]) << std::endl;

		}
	}
};
