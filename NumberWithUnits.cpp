#include <iostream>
using namespace std;
#include "NumberWithUnits.hpp"
#include <string>
namespace ariel{
    NumberWithUnits::NumberWithUnits(double a, string s){
    }
     NumberWithUnits::~NumberWithUnits(){}

         void NumberWithUnits::read_units(std::ifstream& stream){
             
        }

            const NumberWithUnits NumberWithUnits::operator +(const NumberWithUnits& other)const {
                return *this;
            }
            NumberWithUnits& NumberWithUnits::operator +=(const NumberWithUnits& other){
                return *this;
            }

            //onary
            NumberWithUnits& NumberWithUnits::operator +(){
                return*this;
            }
            const NumberWithUnits NumberWithUnits::operator -(const NumberWithUnits& other) const {
             return *this;

            }
            
             NumberWithUnits& NumberWithUnits::operator -=(const NumberWithUnits& other) {
              return *this;
             }
            
            //onary
            NumberWithUnits& NumberWithUnits::operator -(){
                return *this;
            }
            

            bool NumberWithUnits::operator > (const NumberWithUnits& other)const{
                return true;
            }

            
            bool NumberWithUnits::operator >= (const NumberWithUnits& other)const{
                return true;
            }

            
            bool NumberWithUnits::operator < (const NumberWithUnits& other)const{
                return true;
            }

            
            bool NumberWithUnits::operator <= (const NumberWithUnits& other)const{
                return true;
            }

            
            bool  NumberWithUnits::operator == (const NumberWithUnits& other)const{
                return true;
            }

            
            bool  NumberWithUnits::operator != (const NumberWithUnits& other)const{
                return true;
            }

            
            //perfix increment:
            NumberWithUnits& NumberWithUnits::operator ++(){
                return *this;
            }

            
            //postfix:
            const NumberWithUnits& NumberWithUnits::operator ++(int dummy_flag_for_postfix_increment){
                return *this;
            }
            
            //perfix increment:
            NumberWithUnits& NumberWithUnits::operator --(){
                return *this;
            }

            
            //postfix:
            const NumberWithUnits& NumberWithUnits::operator --(int dummy_flag_for_postfix_increment){
                return *this;
            }
            
            const NumberWithUnits operator *(const NumberWithUnits& unit_num, double num){
                return NumberWithUnits(1,"") ;
            }
            const NumberWithUnits operator *(double num, const NumberWithUnits& unit_num){
                return NumberWithUnits(1,"");
            }


             std::ostream& operator << (std::ostream& output, const NumberWithUnits& num){
                 return output;
             }
             std::istream& operator >>(std::istream& input, NumberWithUnits& num){
                 return input ;
             }
};
