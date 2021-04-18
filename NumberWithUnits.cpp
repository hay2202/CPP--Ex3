#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "NumberWithUnits.hpp"
using namespace ariel;

namespace ariel{
          void NumberWithUnits::read_units(ifstream& file){}
            NumberWithUnits a{1,"m"};

            NumberWithUnits operator+(const NumberWithUnits& x, const NumberWithUnits& y) {return a;}
           NumberWithUnits& operator+=(const NumberWithUnits& x, const NumberWithUnits& y){return a;}
            NumberWithUnits operator+(const NumberWithUnits& x)  {return a;}
            NumberWithUnits operator-(const NumberWithUnits& x, const NumberWithUnits& y) {return a;}
           NumberWithUnits& operator-=(const NumberWithUnits& x, const NumberWithUnits& y){return a;}
            NumberWithUnits operator-(const NumberWithUnits& x){return a;}

           bool operator>(const NumberWithUnits& x, const NumberWithUnits& y){return true;}
           bool operator>=(const NumberWithUnits& x, const NumberWithUnits& y){return true;}
           bool operator<(const NumberWithUnits& x, const NumberWithUnits& y){return true;}
           bool operator<=(const NumberWithUnits& x, const NumberWithUnits& y){return true;}
           bool operator==(const NumberWithUnits& x, const NumberWithUnits& y){return true;}
           bool operator!=(const NumberWithUnits& x, const NumberWithUnits& y){return true;}

           NumberWithUnits& operator++(const NumberWithUnits& x){return a;}   //prefix
            NumberWithUnits operator++(const NumberWithUnits& x, int){return a;}    //postfix
           NumberWithUnits& operator--(const NumberWithUnits& x){return a;}
            NumberWithUnits operator--(const NumberWithUnits& x, int){return a;}

           NumberWithUnits& operator*( NumberWithUnits& x, double c){return a;}
           NumberWithUnits& operator*(double c,NumberWithUnits& x){return a;}

            ostream& operator<< (std::ostream& os, const NumberWithUnits& x){return os<<"s";}
            istream& operator>> (std::istream& is, NumberWithUnits& x){return is;}
};