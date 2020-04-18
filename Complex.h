#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED
#include<iostream>
using namespace std;
class Complex
{
private:
    float real,imag;
public:
    Complex();
    Complex(float r, float i);
    Complex(const Complex& z);
    ~Complex();
    Complex& operator =(const Complex &z);
    bool operator==(const Complex&z)const;
    Complex operator +( Complex z );
    Complex operator -(Complex z);
    Complex operator *(Complex z);
    friend ostream& operator <<(ostream &out,const Complex &z);
    friend istream& operator >>(istream &in, Complex &z);
    friend class Matrice;
};


#endif // COMPLEX_H_INCLUDED
