#include "Matrice_patratica.h"
#include <iostream>
using namespace std;
Matrice_patratica::Matrice_patratica():Matrice()
{
    this->dim=0;
}
Matrice_patratica::Matrice_patratica( int d):Matrice(d,d)
{
    this->dim=d;
}
Matrice_patratica::Matrice_patratica(const Matrice_patratica& M):Matrice(M.dim,M.dim)
{
    this->dim=M.dim;
    for(int i=0; i<this->dim; i++)
        for(int j=0; j<this->dim; j++)
            this->set_val(i,j,M.get_val(i,j));

}
ostream& operator<<(ostream &out,const Matrice_patratica&M)
{
    for(int i=0; i<M.dim; i++)
    {
        for(int j=0; j<M.dim; j++)
            out<<M.get_val(i,j)<<"  ";
        out<<"\n";
    }
    return out;
}
istream &operator >>(istream &in, Matrice_patratica &M)
{
    int d;
    cout<<"citeste dimensiune";
    in>>d;
    if(d<0) throw 'a';
    Matrice_patratica M2(d);
    for(int i=0; i<M2.dim; i++)
        for(int j=0; j<M2.dim; j++)
        {
            Complex z;
            in>>z;
            M2.set_val(i,j,z);
        }
    M=M2;
    return in;
}
Matrice_patratica Matrice_patratica::minor(int c) const
{
    Matrice_patratica minor( this->dim-1);
    int k=0,m=0;
    for(int i=1; i<this->dim; i++)
    {
        m=0;
        for(int j=0; j<this->dim; j++)
            if( j!=c)
                minor.set_val(k,m++, this->get_val(i,j));
        k+=1;
    }
    return  minor;

}
Complex determinant(const Matrice_patratica& M)
{
    Complex s;
    if(M.get_dim()==1)
        return M.get_val(0,0);
    else
        for(int i=0; i<M.get_dim(); i++)
            if(i%2==0)
                s=s+M.get_val(0,i)* determinant(M.minor(i));
            else
                s=s -M.get_val(0,i)* determinant(M.minor(i));
    //cout<<M.minor(i);
    return s;
    cout<<"\ndet\n";

}
void Matrice_patratica:: verif_diag()
{
    Complex z;

    for(int i=0; i<this->dim; i++)
        for(int j=0; j<this->dim; j++)
            if(i!=j)
                if (!(this->get_val(i,j)==z))
                {
                    cout<<"nu e diag";
                    return;

                }
    cout<<"e diag";

}

int Matrice_patratica::get_dim() const
{
    return this->dim;
}
Matrice_patratica& Matrice_patratica:: operator=(const Matrice_patratica&M)
{
       if(this!=&M)
        if(M.dim!=this->dim)
        {
            Complex ** w=this->get_point();
            for (int i=0; i<this->dim; i++)
            {
                delete [] w[i];
            }
            delete []w;
            this->dim=M.dim;
            this->alocare(M.dim,M.dim);
        }
    for(int i=0; i<dim; i++)
        for(int j=0; j<dim; j++)
            this->set_val(i,j,M.get_val(i,j));

    return *this;
}
void Matrice_patratica::citire_afisare()
{
    int n;
    cout << "Introduceti numarul de matrici patratice: ";
    cin >> n;

    Matrice_patratica* w = new Matrice_patratica[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"citeste_matrice_urmatoare\n";
        cin >> w[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << w[i] << endl;
        cout<<determinant(w[i])<<"\n";
    }
    delete[] w;
}
Matrice_patratica::~Matrice_patratica()
{
    Complex ** w=this->get_point();
    for (int i=0; i<this->dim; i++)
    {
        delete [] w[i];
    }
    cout<<"destr_deriv";
}
