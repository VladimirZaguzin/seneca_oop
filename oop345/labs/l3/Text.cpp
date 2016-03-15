
//#pragma once
#include "Text.h"
#define DEBUG

#include <fstream>
#include <iostream>
#include <string>


using namespace std;

namespace w3 {

    class Text {
        string* lineTable;
        size_t lineCount;
    public:
        ~ Text() { if (lineTable) delete[] lineTable; };

        Text() : lineCount(0), lineTable(nullptr) { };

        Text(const char* filename) : lineCount(0), lineTable(nullptr) {

            fstream fs(filename);
            string s;
            if (fs.is_open()) {
                while (getline(fs, s)) {
                    lineCount++;
                }
#ifdef DEBUG
                cout << "file" << filename << " containts" << lineCount << " lines\n";
                lineTable = new string[lineCount];
#endif

                fs.clear();             // reset error state
                fs.seekp(0, ios::beg);  // postiton file offet 0 from the beginning (which is beginning)
                for (size_t l = 0; l < lineCount; l++) {
                    getline(fs, lineTable[l]);
                }
#ifdef DEBUG
                for(size_t l = 0; l < lineCount; l++){
                    cout << "line " << l << "-->" << lineTable[l] << "\n";
                }
#endif
            }
            else {
                cerr << "Cannot open file -->" << filename << "<--\n";
            }
        }

        // assignment operator
        Text &operator=(const Text &rhs) {
            if (this != &rhs) {
                if (lineTable) delete[] lineTable;

                //deep copy
                lineCount = rhs.lineCount;
                lineTable = new string[lineCount];

                for (size_t l = 0; l < lineCount; l++) {
                    lineTable[l] = rhs.lineTable[l];
                }


            }
            return *this;
        }

        // copy constructor
        Text(const Text &rhs) {
            lineTable = nullptr;
            *this = rhs;
        }

        // move assignment operator
        Text& operator=(Text &&rhs) {
            if (this != &rhs) {
                if (lineTable) { delete[] lineTable; };

                lineCount = rhs.lineCount;
                lineTable = new string[lineCount];

                for (size_t l = 0; l < lineCount; l++) {
                    lineTable[l] = rhs.lineTable[l];
                }


            }
            return *this;
        }

        // move constructor
        Text(Text&& rhs) {
            lineTable = nullptr;
            *this = rhs;
        }


        size_t size() const { return lineCount; }
    };
} //namespace w3