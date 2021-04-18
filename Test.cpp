/**
 * AUTHORS: Hay Asa
 * Date: 2021-02
 */

#include "doctest.h"
#include "NumberWithUnits.hpp"
#include <string>
#include <stdexcept>
#include <algorithm>
using namespace std;

using namespace ariel;
ariel::NumberWithUnits a(2,"km");
ariel::NumberWithUnits b(200,"m");
ariel::NumberWithUnits c(2,"km");
ariel::NumberWithUnits d(2,"kg");

TEST_CASE("Operator EQL tests") {
    CHECK(a==c);
    CHECK(10*b == a);
    CHECK_FALSE(a==b);
    CHECK_THROWS(a=d);
}

TEST_CASE("Operator NEQ tests") {
    CHECK(a!=b);
    CHECK_FALSE(a!=c);
    //CHECK_THROWS(a!=d);
}

TEST_CASE("Operator GET tests") {
    CHECK(a > b);
    CHECK_FALSE(a > c);
   // CHECK_THROWS(b > d);
}

TEST_CASE("Operator GEQ tests") {
    CHECK(a >= b);
    CHECK(a >= c);
    CHECK_FALSE(b >= a);
    //CHECK_THROWS(b >= d);
}

TEST_CASE("Operator LET tests") {
    CHECK(b < c);
    CHECK_FALSE(a < b );
   // CHECK_THROWS(b < d);
}

TEST_CASE("Operator LEQ tests") {
    CHECK(b <= c);
    CHECK(a <= c);
    CHECK_FALSE(a <= b );
    //CHECK_THROWS(b <= d);
}

TEST_CASE("Operator PLUS tests") {  
    CHECK((a+b) == NumberWithUnits {2.2, "km"});
    CHECK((a+c) == NumberWithUnits {4, "km"});
    CHECK_THROWS(a+d);
}



TEST_CASE("Operator MINUS tests") {
    CHECK((a-b) == NumberWithUnits {1.8, "km"});
    CHECK((c-a) == NumberWithUnits {0, "km"});
    CHECK_THROWS(a-d);
}

TEST_CASE("Operator += tests") {
    CHECK((a+=c) == NumberWithUnits {4, "km"});
    CHECK((b+=a) == NumberWithUnits {2200, "m"});
    CHECK_THROWS(a+=d);
}