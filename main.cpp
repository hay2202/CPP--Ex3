/**
 * main file for the exercise on numbers with units
 *
 * @author Hay Asa
 * @since 2019-02
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "NumberWithUnits.hpp"
using namespace ariel;

int main() {
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);

    NumberWithUnits a (2, "km");
    NumberWithUnits b (500, "m");
    NumberWithUnits c (2000, "kg");
    NumberWithUnits d (2000, "mm");
    NumberWithUnits e (2, "ton");

    cout << boolalpha; // print booleans as strings from now on:

    cout << (a+b) <<endl;
    cout << (a+d) <<endl;
    cout << (c+e) <<endl;

    cout << (a>b) <<endl;
    cout << (a!=d) <<endl;
    cout << (c==e) <<endl;

    try {
    cout << (a+c) << endl;  
  } catch (const std::exception& ex) {
        cout << ex.what() << endl; 
  }

  istringstream sample_input{"700 [ kg ]"};
  sample_input >> a;
  cout << a << endl;   
  cout << (a+c) << endl; 
  cout << a++ << endl; 
  cout << ++a << endl; 

  
  a += (NumberWithUnits (1,"ton"));
  cout << a << endl;

  cout << "\nEnd of demo!" << endl;
  return 0;
}
