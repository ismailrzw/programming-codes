#include <iostream>
using namespace std;

class RationalNumber{
public:
RationalNumber(){
numerator = 0;
denominator = 1;
cout<<"RationalNumer -- "<<" Default constructor called"<<endl;
}
RationalNumber(int n,int d){
numerator = n;
setDenominator(d);
simplify();
cout<<"RationalNumer -- Default constructor called"<<endl;
}
void print(){
cout<<numerator<<" / "<<denominator<<endl;
}
int getNumerator(){
return numerator;
}
void setNumerator(int n){
numerator = n;
}
int getDenominator(){
return denominator;
}
void setDenominator(int d){
denominator = (d > 0 ) ? d : 1;
}
~RationalNumber(){
cout<<"RationalNumer -- Default destructor called"<<endl;
}

RationalNumber add(RationalNumber r){
int lcm = this->denominator * r.denominator;
int n1 = (this->numerator * lcm ) / this->denominator;
int n2 = (r.numerator * lcm) / r.denominator;
return RationalNumber (n1+n2 , lcm);
}
RationalNumber sub(RationalNumber r){
int lcm = this->denominator * r.denominator;
int n1 = (this->numerator * lcm ) / this->denominator;
int n2 = (r.numerator * lcm) / r.denominator;
return RationalNumber (n1-n2 , lcm);
}
RationalNumber mul(RationalNumber r){
int n = this->numerator * r.numerator;
int d = this->denominator * r.denominator;
return RationalNumber (n , d);
}
RationalNumber div(RationalNumber r){
int n = this->numerator * r.denominator;
int d = this->denominator * r.numerator;
return RationalNumber (n , d);
}
private:
int numerator;
int denominator;

void simplify(){
int div = 2;
int min = (numerator > denominator ) ? denominator : numerator;
while(div <= min){
if(numerator % div == 0 && denominator % div == 0 ) {
numerator = numerator / div;
denominator = denominator / div;
}else{
div++;
}
}
}

};

int main() {
{
RationalNumber r1(3,9);
RationalNumber r2(4,16);
r1.print();
r2.print();
RationalNumber r3 = r1.add(r2);
r3.print();
RationalNumber r4 = r1.sub(r2);
r4.print();
}
return 0;
}