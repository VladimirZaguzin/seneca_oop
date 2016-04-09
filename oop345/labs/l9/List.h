#pragma once


#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>


namespace w9 {
    template <typename T>
    class List {
        std::vector<T> list;
    public:
        List() { }
        List(const char* fn) {
            std::ifstream file(fn);
            if (!file)
                throw std::string("*** Failed to open file ") +
                      std::string(fn) + std::string(" ***");
            while (file) {
                T e;
                if (e.load(file))
                    list.push_back(*new T(e));
            }
        }
        size_t size() const { return list.size(); }
        const T& operator[](size_t i) const { return list[i]; }

        void operator+=(std::unique_ptr<Product> &p) {
            list.push_back(std::move(*p));
        }

        void display(std::ostream& os) const {
            os << std::fixed << std::setprecision(2);
            for (auto& e : list)
                e.display(os);
        }

    };

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const List<T>& l) {
        l.display(os);
        return os;
    }
}