#pragma once

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include <map>

namespace ariel{
    class NumberWithUnits
    {
    private:
        double num;
        string type;
        static bool valid_unit(const NumberWithUnits& x, const NumberWithUnits& y);
        static double convert(const NumberWithUnits& to, const NumberWithUnits& from);
        bool valid_unit(const NumberWithUnits& x);
        double convert(const NumberWithUnits& from);


    public:
        static map <string, map<string, double>> units_list;
        NumberWithUnits(double n, string s): num(n), type(s){
            if (units_list.count(s)==0)
            {
                throw std::out_of_range{"Error!! invalid unit! \n"};
            }
            
        };
        ~NumberWithUnits();
        
        static void read_units(ifstream& file);

        friend NumberWithUnits operator+(const NumberWithUnits& x, const NumberWithUnits& y) ;
        NumberWithUnits& operator+=(const NumberWithUnits& x);
        friend  NumberWithUnits operator+(const NumberWithUnits& x) ;
        friend  NumberWithUnits operator-(const NumberWithUnits& x, const NumberWithUnits& y);
        NumberWithUnits& operator-=(const NumberWithUnits& x);
        friend  NumberWithUnits operator-(const NumberWithUnits& x);

        friend bool operator>(const NumberWithUnits& x, const NumberWithUnits& y);
        friend bool operator>=(const NumberWithUnits& x, const NumberWithUnits& y);
        friend bool operator<(const NumberWithUnits& x, const NumberWithUnits& y);
        friend bool operator<=(const NumberWithUnits& x, const NumberWithUnits& y);
        friend bool operator==(const NumberWithUnits& x, const NumberWithUnits& y);
        friend bool operator!=(const NumberWithUnits& x, const NumberWithUnits& y);

         NumberWithUnits& operator++();   //prefix
         const NumberWithUnits operator++( int);    //postfix
         NumberWithUnits& operator--();
         const NumberWithUnits operator--( int);

        friend NumberWithUnits operator*( const NumberWithUnits& x, const double c);
        friend NumberWithUnits operator*(const double c,const NumberWithUnits& x);

        friend std::ostream& operator<< (std::ostream& os, const NumberWithUnits& x);
        friend std::istream& operator>> (std::istream& is, NumberWithUnits& x);


    };


};