#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
using namespace std;

#include "NumberWithUnits.hpp"
using namespace ariel;

#define EPSILON 0.001

namespace ariel{
    map <string, map<string, double>> NumberWithUnits::units_list;

    NumberWithUnits::~NumberWithUnits(){}

          void NumberWithUnits::read_units(ifstream& file){
        if (file.is_open())
        {
            string  from, to, eql;
            double first=0 ,size=0;

            while (file >> first >> from >> eql >> size >> to)
            {
                units_list[from][to] = size;
                units_list[to][from] = 1/size;
                   for(auto& i : units_list[from]){
                    if (i.first != to){
                        units_list[i.first][to] = units_list[i.first][from]*size;
                        units_list[to][i.first] =i.second * 1/size ;
                    }
                }

                for(auto& i : units_list[to]){
                    if (i.first != from){
                        units_list[i.first][from] = units_list[i.first][to]*1/size;
                        units_list[from][i.first] =i.second * size ;
                    }
                }

            }
            cout << "Units loaded successfully!" << endl;
        }
        else
        {
            cout << "Unable to open file";
        }

        file.close();
    }

    NumberWithUnits operator+(const NumberWithUnits& x, const NumberWithUnits& y) {
        if (!NumberWithUnits::valid_unit(x,y)){
            throw std::out_of_range{"Error!! not the same unit! \n"};
        }
         double size =1;
        if (x.type != y.type)
        {
         size = NumberWithUnits :: convert(x,y);
        }
        size = y.num*size+x.num;
       return NumberWithUnits (size,x.type);
    }

    NumberWithUnits& NumberWithUnits:: operator+=(const NumberWithUnits& x){
        if (!this->valid_unit(x)){
            throw std::out_of_range{"Error!! not the same unit! \n"};
        }
         double size =1;
        if (type != x.type)
        {
         size = this->convert(x);
        }
        num += x.num*size;
        return *this;
    }

    NumberWithUnits operator+(const NumberWithUnits& x)  {return x;}

    NumberWithUnits operator-(const NumberWithUnits& x, const NumberWithUnits& y) {
        if (!NumberWithUnits::valid_unit(x,y)){
            throw std::out_of_range{"Error!! not the same unit! \n"};
        }
       double size =1;
        if (x.type != y.type)
        {
         size = NumberWithUnits :: convert(x,y);
        }
        size = x.num - (y.num*size);
        return NumberWithUnits (size,x.type);
    }

    NumberWithUnits& NumberWithUnits:: operator-=(const NumberWithUnits& x){
        if (!this->valid_unit(x)){
            throw std::out_of_range{"Error!! not the same unit! \n"};
        }
        double size =1;
        if (type != x.type)
        {
         size = this->convert(x);
        }
        num -= x.num*size;
        return *this;
    }

    NumberWithUnits operator-(const NumberWithUnits& x){ return NumberWithUnits (-x.num,x.type); }

    bool operator>(const NumberWithUnits& x, const NumberWithUnits& y){
        if (!NumberWithUnits::valid_unit(x,y)){
            throw std::out_of_range{"Error!! not the same unit! \n"};
        }
         double size =1;
        if (x.type != y.type)
        {
         size = NumberWithUnits :: convert(x,y);
        }
        
        if (size == 1 && x.num > y.num){
            return true;
        }
        else{
            double temp = size * y.num;
            if (x.num > temp)
                return true;
        }
        return false;
    }

    bool operator>=(const NumberWithUnits& x, const NumberWithUnits& y){
        if (!NumberWithUnits::valid_unit(x,y)){
            throw std::out_of_range{"Error!! not the same unit! \n"};
        }
        double size =1;
        if (x.type != y.type)
        {
         size = NumberWithUnits :: convert(x,y);
        }
        
        if (size == 1 && x.num >= y.num){
            return true;
        }
        else{
            double temp = size * y.num;
            if (x.num >= temp)
                return true;
        }
        return false;
    }

    bool operator<(const NumberWithUnits& x, const NumberWithUnits& y){
        if (!NumberWithUnits::valid_unit(x,y)){
            throw std::out_of_range{"Error!! not the same unit! \n"};
        }
        double size =1;
        if (x.type != y.type)
        {
         size = NumberWithUnits :: convert(x,y);
        }
        
        if (size == 1 && x.num < y.num){
            return true;
        }
        else{
            double temp = size * y.num;
            if (x.num < temp)
                return true;
        }
        return false;
    }

    bool operator<=(const NumberWithUnits& x, const NumberWithUnits& y){
        if (!NumberWithUnits::valid_unit(x,y)){
            throw std::out_of_range{"Error!! not the same unit! \n"};
        }
        double size =1;
        if (x.type != y.type)
        {
         size = NumberWithUnits :: convert(x,y);
        }
        
        if (size == 1 && x.num <= y.num){
            return true;
        }
        else{
            double temp = size * y.num;
            if (x.num <= temp)
                return true;
        }
        return false;
    }
    
    bool operator==(const NumberWithUnits& x, const NumberWithUnits& y){
        if (!(NumberWithUnits::valid_unit(x,y))){
            throw std::out_of_range{"Error!! not the same unit! \n"};
        }
        double size =1;
        if (x.type != y.type)
        {
         size = NumberWithUnits :: convert(x,y);
        }
        
        if (size == 1 && abs((x.num -y.num)) < EPSILON){
            return true;
        }
        else{
            double temp = size * y.num;
            if (abs((x.num -temp)) < EPSILON){
                return true;
            }    
        }
        return false;
    }

    bool operator!=(const NumberWithUnits& x, const NumberWithUnits& y){return !(x==y);}

    NumberWithUnits& NumberWithUnits:: operator++(){         //prefix
        this->num++;
        return *this;
    }

    const NumberWithUnits NumberWithUnits::operator++(int){      //postfix
        double n = num;
        this->num++;
        return NumberWithUnits (n, type);
    }

    NumberWithUnits& NumberWithUnits:: operator--(){
        this->num--;
        return *this;
    }

    const NumberWithUnits NumberWithUnits::operator--(int){
        double n = num;
        this->num--;
        return NumberWithUnits (n, type);
    }

    NumberWithUnits operator*(const NumberWithUnits& x, const double c){
        return NumberWithUnits  (x.num*c, x.type);
    }

    NumberWithUnits operator*(const double c,const NumberWithUnits& x){
        return NumberWithUnits {x.num*c, x.type};
    }

    ostream& operator<< (std::ostream& os, const NumberWithUnits& x){ return os << x.num << "[" << x.type << "]"; }

    istream& operator>> (std::istream& is, NumberWithUnits& x){
        char t,u ;
        string unit;
        is >> x.num >> t ;
        is >> u;
        while (u != ']'){
            unit+=u;
            is >> u;
        }
        if (NumberWithUnits:: units_list.count(unit)==0)
            {
                throw std::out_of_range{"Error!! invalid unit! \n"};
            }
        x.type = unit;
        return is;
    }


//check validation of two objects (static and non-static)
    bool NumberWithUnits::valid_unit(const NumberWithUnits& x, const NumberWithUnits& y){
        if (x.type == y.type)
        {
            return true;
        }
        if (units_list[x.type].count(y.type) > 0)
        {
            return true;
        }

        return false;
    }

    bool NumberWithUnits::valid_unit(const NumberWithUnits& y){
       if (type == y.type)
        {
            return true;
        }

        if (units_list[type].count(y.type) > 0)
        {
            return true;
        }

        return false;
    }
    
//convert size unit (static and non-static)
    double NumberWithUnits::convert(const NumberWithUnits& to, const NumberWithUnits& from){
        return 1/NumberWithUnits ::units_list[to.type][ from.type];
    }

    double NumberWithUnits::convert(const NumberWithUnits& from){
        return 1/NumberWithUnits ::units_list[type][from.type];
    }

};