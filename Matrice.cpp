#include "Matrice.h"
Matrice::Matrice()
{
    v=NULL;

}
Matrice::Matrice(int lin,int col)
{   Complex z;
    //initializam cu z matricea
    this->alocare(lin,col);
    for(int i=0; i<lin; i++)
        for(int j=0; j<col; j++)
            v[i][j]=z;

}

Complex Matrice:: get_val(int i, int j) const
{
    return  v[i][j];
}
void Matrice::set_val(int i, int j, const Complex& z)
{     v[i][j]=z;
}
Complex** Matrice::get_point() const
{
    return v;
}
void Matrice::alocare(int l, int c){
      v= new Complex *[l];
    for(int i=0; i<l; i++)
        v[i]=new Complex[c];

}
 Matrice::  ~Matrice()
{
    if(v!=NULL)
        delete []v;

}
