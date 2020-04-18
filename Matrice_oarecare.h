#ifndef MATRICE_OARECARE_H_INCLUDED
#define MATRICE_OARECARE_H_INCLUDED

#include "Matrice.h"
#include <iostream>
using namespace std;
class Matrice_oarecare : public Matrice
{
private:
    int lin;
    int col;
public:
    Matrice_oarecare();
    Matrice_oarecare(int l, int c);
    Matrice_oarecare(const Matrice_oarecare&M);
    ~Matrice_oarecare();
    void verif_diag();
     void citire_afisare();

    Matrice_oarecare& operator=(const Matrice_oarecare&M);
    friend ostream& operator <<(ostream &out,const Matrice_oarecare &M);
    friend istream& operator >>(istream &in, Matrice_oarecare &M);

};
#endif // MATRICE_OARECARE_H_INCLUDED
