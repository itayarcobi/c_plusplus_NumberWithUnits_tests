#pragma once
#include <string>
#include <iostream>
#include<unordered_map>
namespace ariel {
        class NumberWithUnits{
            //  std::unordered_map<double,string> numconv;
             double num;
             std::string s;
            // std::unordered_map* p =&numconv;
            public:
            NumberWithUnits(double a, std::string s);
            ~NumberWithUnits();
                // delete NumberWithUnits::numconv;
        
            static void read_units(std::ifstream& stream);
            const NumberWithUnits operator +(const NumberWithUnits& other) const;
            NumberWithUnits& operator += (const NumberWithUnits& other);
            
            //onary
            NumberWithUnits& operator +();
            
            const NumberWithUnits operator -(const NumberWithUnits& other) const;
            
             NumberWithUnits& operator -=(const NumberWithUnits& other) ;
            
            //onary
            NumberWithUnits& operator -();
            

            bool operator > (const NumberWithUnits& other)const;

            
            bool operator >= (const NumberWithUnits& other)const;

            
            bool operator < (const NumberWithUnits& other)const;

            
            bool operator <= (const NumberWithUnits& other)const;

            
            bool  operator == (const NumberWithUnits& other)const;

            
            bool  operator != (const NumberWithUnits& other)const;

            
            //perfix increment:
            NumberWithUnits& operator ++();

            
            //postfix:
            const NumberWithUnits& operator ++(int dummy_flag_for_postfix_increment);
            
            //perfix increment:
            NumberWithUnits& operator --();

            
            //postfix:
            const NumberWithUnits& operator --(int dummy_flag_for_postfix_increment);
            
            friend const NumberWithUnits operator *(const NumberWithUnits& unit_num, double num);
            friend const NumberWithUnits operator *(double num, const NumberWithUnits& unit_num);


            friend std::ostream& operator << (std::ostream& output, const NumberWithUnits& num);
            friend std::istream& operator >>(std::istream& input, NumberWithUnits& num);

           
        };
}