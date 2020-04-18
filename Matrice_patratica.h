#ifndef MATRICE_PATRATICA_H_INCLUDED
#define MATRICE_PATRATICA_H_INCLUDED

#include "Matrice.h"
#include <iostream>
using namespace std;
class Matrice_patratica :public Matrice{
private:
    int dim;
public:
       Matrice_patratica();
       Matrice_patratica(int dim);
       Matrice_patratica(const Matrice_patratica& M);
       ~Matrice_patratica();
       void verif_diag();
       int get_dim() const;
       Matrice_patratica  minor( int c) const;

       Matrice_patratica& operator=(const Matrice_patratica&M);
       friend Complex  determinant(const Matrice_patratica &M);
       friend ostream& operator<<(ostream&,const Matrice_patratica&M);
       friend istream& operator>>(istream &, Matrice_patratica&M);

      void citire_afisare();
};

#endif // MATRICE_PATRATICA_H_INCLUDED
