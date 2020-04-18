#include "Complex.h"
#include <iostream>
Complex::Complex()
{

    real=0;
    imag=0;
}
Complex::Complex( float r, float i)
{
    real=r;
    imag=i;
}
Complex::Complex(const Complex &z)
{
    real=z.real;
    imag=z.imag;
}
Complex::~Complex()
{
    real=0;
    imag=0;
}

ostream &operator <<(ostream &out, const Complex &z)
{
    out<<z.real;
    out<<"+i*"<<z.imag;
    return out;
}
istream &operator>>(istream &in, Complex &z)
{
    cout<<"Partea reala:";
    in>>z.real;
    cout<<"Partea imag:";
    in>>z.imag;
    return in;

}
Complex& Complex::operator=(const Complex& z)
{  if(this!=&z)
    {this->real=z.real;
   this->imag=z.imag;}

   return *this;

}
bool Complex:: operator==(const Complex&z)const{
   if(this->real==z.real and this->imag==z.imag)
      return 1;
    return 0;

}
 Complex Complex::operator +( Complex z ){
     Complex rez;
     rez.real=this->real+z.real;
     rez.imag=this->imag+z.imag;
     return rez;
 }
  Complex Complex::operator -( Complex z ){
     Complex rez;
     rez.real=this->real-z.real;
     rez.imag=this->imag-z.imag;
     return rez;
 }
  Complex Complex::operator *( Complex z ){
     Complex rez;
     rez.real=this->real*z.real-this->imag*z.imag;
     rez.imag=this->imag*z.real+this->real*z.imag;;
     return rez;
 }

