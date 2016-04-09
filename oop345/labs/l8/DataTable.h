#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <numeric>

using namespace std;

namespace w8 {
    template<class T>
    class DataTable {
		
        std::vector<T> HighSchoolvector;
        std::vector<T> CollegeVector;

    public:
	
        DataTable() {}

        DataTable(std::ifstream& dataFile, const int FW, const int ND) {

            double HighSchoolTemplate, CollegeTemplate;

            while(dataFile >> HighSchoolTemplate >> CollegeTemplate){
                HighSchoolvector.push_back(HighSchoolTemplate);
                CollegeVector.push_back(CollegeTemplate);
            }
        }

		
        T mean() const {
            return std::accumulate(CollegeVector.begin(), CollegeVector.end(), 0.) / CollegeVector.size();
        } 
		
		
        T sigma() const {
            T average = mean();
            size_t vecSize = CollegeVector.size();
            T sumOfVec = 0;

            for(size_t index = 0; index < vecSize; ++index){
                sumOfVec += pow((CollegeVector[index] - average), 2);
            }


            return sqrt(sumOfVec/(vecSize - 1));

        } 

        T median() const {

            size_t vecSize = CollegeVector.size();

            vector<T> bufferVec(CollegeVector);
            std::sort(bufferVec.begin(), bufferVec.end());

            if(vecSize % 2 == 0){
                return (bufferVec[(vecSize/2 - 1)] + bufferVec[(vecSize/2)]) / 2;
            }
            else{
                size_t medianElement = (vecSize - 1)/2 + 1;
                return bufferVec[medianElement - 1];
            }

        } 
        void regression(T &slope, T &y_intercept) const {
                if(HighSchoolvector.size() == 0) 
                    throw std::string("Need 1 or more data points to fit a linear regression line.");

                if(HighSchoolvector.size() != CollegeVector.size())
                    throw std::string("What? HighSchoolvector+CollegeVector sizes are different!");

                double SX = 0.,  SY = 0.,  SXX = 0., SYY = 0.,  SXY = 0.;

                for (int i = 0; i < HighSchoolvector.size(); i++) {
                    SX  += HighSchoolvector[i];
                    SY  += CollegeVector[i];
                    SXX += HighSchoolvector[i] * HighSchoolvector[i];
                    SYY += CollegeVector[i] * CollegeVector[i];
                    SXY += HighSchoolvector[i] * CollegeVector[i];
                }

                size_t n = CollegeVector.size();

				SX =   std::accumulate(HighSchoolvector.begin(), HighSchoolvector.end(), double(0.),
                                       [] (double sum, double element) { return sum + element; }
                );

                SY  =  std::accumulate(CollegeVector.begin(), CollegeVector.end(), double(0.));

                SXX =  std::accumulate(HighSchoolvector.begin(), HighSchoolvector.end(), double(0.),
                                       [] (double sum, double element)
                                       { return sum + element * element; }
									   );
                SXY =  std::inner_product(HighSchoolvector.begin(), HighSchoolvector.end(),
                                          CollegeVector.begin(), double(0.));

                slope      =  (n*SXY - SX*SY)    / (n*SXX - SX*SX);
                y_intercept  =  (SY - slope * SX) / n;

        } // - returns the slope and intercept for the data set




        void display(std::ostream &os) const {



            os << std::fixed << std::right << std::setw(4) << "X";
            os << "  ";
            os << std::fixed << std::right << std::setw(5) << "Y";
            os << std::endl;
            size_t index = 0;

            for (T elem : HighSchoolvector){
                os << std::setw(4) << std::fixed << std::setprecision(2) << std::right << elem;
                os << "  ";

                os << std::setw(5) << std::fixed << std::setprecision(2) << CollegeVector[index++];
                os << std::endl;
            }


        } // - displays the data pairs as shown below
    };

    template<class ST>
    std::ostream &operator<<(std::ostream &os, const DataTable<ST> &data) {
        data.display(os);
        return os;
    } 

}