#ifndef MATRICE_H_INCLUDED
#define MATRICE_H_INCLUDED

#include "Complex.h"
class Matrice  //clasa abstracta
{
private:
    Complex **v;
public:
    Matrice();
    Matrice( int lin,int col);
    virtual void verif_diag()=0;// metoda virtuala pura
    Complex  get_val(int i, int j)const;
    void set_val(int i, int j,const Complex& z);
    Complex ** get_point() const;
    virtual ~Matrice();
    virtual void citire_afisare()=0;//metoda virtuala pura
     void alocare(int l, int c);
};


#endif // MATRICE_H_INCLUDED
