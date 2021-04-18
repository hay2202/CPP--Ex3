#pragma once

#include <iostream>
#include <fstream>
using namespace std;

namespace ariel{
    class NumberWithUnits
    {
        private:
            double num;
            string type;

        public:
            NumberWithUnits(double n, string s): num(n), type(s){}
           // ~NumberWithUnits();

           static void read_units(ifstream& file);

           friend NumberWithUnits operator+(const NumberWithUnits& x, const NumberWithUnits& y) ; 
           friend NumberWithUnits& operator+=(const NumberWithUnits& x, const NumberWithUnits& y);
           friend  NumberWithUnits operator+(const NumberWithUnits& x) ;
           friend  NumberWithUnits operator-(const NumberWithUnits& x, const NumberWithUnits& y);
           friend NumberWithUnits& operator-=(const NumberWithUnits& x, const NumberWithUnits& y);
           friend  NumberWithUnits operator-(const NumberWithUnits& x);

           friend bool operator>(const NumberWithUnits& x, const NumberWithUnits& y);
           friend bool operator>=(const NumberWithUnits& x, const NumberWithUnits& y);
           friend bool operator<(const NumberWithUnits& x, const NumberWithUnits& y);
           friend bool operator<=(const NumberWithUnits& x, const NumberWithUnits& y);
           friend bool operator==(const NumberWithUnits& x, const NumberWithUnits& y);
           friend bool operator!=(const NumberWithUnits& x, const NumberWithUnits& y);

           friend NumberWithUnits& operator++(const NumberWithUnits& x);   //prefix
           friend  NumberWithUnits operator++(const NumberWithUnits& x, int);    //postfix
           friend NumberWithUnits& operator--(const NumberWithUnits& x); 
           friend  NumberWithUnits operator--(const NumberWithUnits& x, int);

           friend NumberWithUnits& operator*(NumberWithUnits& x, double c);
           friend NumberWithUnits& operator*(double c,NumberWithUnits& x);

            friend std::ostream& operator<< (std::ostream& os, const NumberWithUnits& x);
            friend std::istream& operator>> (std::istream& is, NumberWithUnits& x);



    };
        

};