#include "doctest.h"
#include "NumberWithUnits.hpp"

#include <string>
#include <algorithm>

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;


using namespace ariel;
    //distance
   NumberWithUnits km1{10,"km"};   // 10 kilometers
    NumberWithUnits km2{2,"km"};   // 2 kilometers
    NumberWithUnits km5{5,"km"};   // 5 kilometers

    NumberWithUnits m1{100,"m"};   // 100 meter
    NumberWithUnits m7{7500,"m"};   // 7500 meter
    //weight
    NumberWithUnits ton1{1,"ton"};   // 1 ton
    NumberWithUnits ton3{3.5,"ton"};   // 3.5 ton
    NumberWithUnits kg1{1000,"kg"};   // 1000 kg
    NumberWithUnits g5{500,"g"};   // 500 g
    NumberWithUnits kg2{1000.5,"kg"};   // 1000.5 kg
    NumberWithUnits ton9{1.9,"ton"};   // 1.9 ton
    //time
    NumberWithUnits hour1{1,"hour"};   // 1 hour
    NumberWithUnits min4{40,"min"};   // 40 min
    NumberWithUnits min04{4,"min"};   // 4 min
    //money
    NumberWithUnits usd1{1,"USD"};   // 1 usa dolar


TEST_CASE("Good code") {

ifstream my_file{"units.txt"};
NumberWithUnits::read_units(my_file);

    CHECK_EQ(NumberWithUnits{1,"km"},NumberWithUnits{1000,"m"});
    CHECK_EQ(NumberWithUnits{1,"m"},NumberWithUnits{100,"cm"});
    CHECK_EQ(NumberWithUnits{1,"kg"},NumberWithUnits{1000,"g"});
    CHECK_EQ(NumberWithUnits{1,"ton"},NumberWithUnits{1000,"kg"});
    CHECK_EQ(NumberWithUnits{1,"hour"},NumberWithUnits{60,"min"});
    CHECK_EQ(NumberWithUnits{1,"min"},NumberWithUnits{60,"sec"});
    CHECK_EQ(NumberWithUnits{1,"USD"},NumberWithUnits{3.33,"ILS"});

    CHECK((km1==km5+km5));
    CHECK((km1-km5==km5));
    CHECK((km5-km1==-km5));
    CHECK((km1==km5*2));
    CHECK((km1>km5));
    CHECK(!(km1>km2));
    CHECK((km1>=km5+km5));
    CHECK((km1<=km5+km5));

    CHECK((km2>m1*10));
    CHECK((km2<=m1*20));
    CHECK((m7>km5));
    CHECK((m7<km1));

    CHECK(ton3>(ton1*3)+g5);
    CHECK((kg1+=g5)==kg2);//kg1=1000.5 ----> 1000kg + (500g == 0.5 kg)= 1000.5 kg
    CHECK((kg1-=g5)==NumberWithUnits{1,"kg"}); //kg1=1000
    CHECK((ton3-=ton1)-kg1==ton9);

    CHECK(hour1+min4==NumberWithUnits{1.4,"hour"});
    CHECK(hour1+min04==NumberWithUnits{1.04,"hour"});

    CHECK(usd1>NumberWithUnits{3,"ILS"});


}
TEST_CASE("Bad code") {

    CHECK_THROWS((kg2+m7));
    CHECK_THROWS((kg2+m7));
    CHECK_THROWS((hour1+g5));
    CHECK_THROWS((min4+ton1));

    CHECK_THROWS((NumberWithUnits{1,"usd"}));
    CHECK_THROWS((NumberWithUnits{20,"TON"}));
    CHECK_THROWS((NumberWithUnits{400,"meter"}));
    CHECK_THROWS((NumberWithUnits{7,"h"}));

}
