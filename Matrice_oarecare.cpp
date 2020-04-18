#include "Matrice_oarecare.h"
#include <iostream>
using namespace std;
Matrice_oarecare::Matrice_oarecare():Matrice()
{   this->lin=0;
    this->col=0;

}
Matrice_oarecare::Matrice_oarecare(int lin, int col): Matrice(lin, col) // va avea 0 peste tot
{   this->lin=lin;
    this->col=col;

}
void Matrice_oarecare:: verif_diag(){
      Complex z;

      for(int i=0; i<this->lin; i++)
        for(int j=0; j<this->col; j++)
               if(i!=j)
               if (!(this->get_val(i,j)==z))
                  {cout<<"Nu e diagonala\n";
                  return;

                  }
    cout<<"E diagonala\n";

}
Matrice_oarecare::Matrice_oarecare(const Matrice_oarecare& M):Matrice(M.lin,M.col)
{
    this->lin=M.lin;
    this->col=M.col;

    for(int i=0; i<lin; i++)
        for(int j=0; j<col; j++)
                this->set_val(i,j,M.get_val(i,j));

}
ostream& operator<<(ostream &out,const Matrice_oarecare&M)
{
    for(int i=0; i<M.lin; i++)
    {
        for(int j=0; j<M.col; j++)
            out<<M.get_val(i,j)<<"  ";
        out<<"\n";
    }
    return out;
}
istream &operator >>(istream &in, Matrice_oarecare &M)
{  cout<<"citeste linie:";
   int l, c;
   in>>l;
   if(l<0) throw 2000;
   cout<<"citeste coloana:";
   in>>c;
   if(c<0) throw 3000.5;
    Matrice_oarecare M2(l,c);
    for(int i=0; i<M2.lin; i++)
        for(int j=0; j<M2.col; j++)
            {Complex z;
                in>>z;
            M2.set_val(i,j,z);
            }
    M=M2;
    return in;

}
Matrice_oarecare& Matrice_oarecare:: operator=(const Matrice_oarecare&M)
{  if(this!=&M)
      if(M.lin!=this->lin || M.col!=this->col)
      {  Complex ** w=this->get_point();
          for (int i=0;i<this->lin;i++)
           {
           delete [] w[i];
           }
         delete []w;
         this->lin=M.lin;
         this->col=M.col;
         this->alocare(M.lin,M.col);
      }
        for(int i=0; i<lin; i++)
        for(int j=0; j<col; j++)
                this->set_val(i,j,M.get_val(i,j));

        return *this;
}
void Matrice_oarecare::citire_afisare()
{
    int n;
    cout << "Introduceti numarul de matrici oarecare: \n";
    cin >> n;

    Matrice_oarecare* w = new Matrice_oarecare[n];
    for (int i = 0; i < n; i++)
    {   cout<<"citeste_matrice_urmatoare\n";
        cin >> w[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << w[i] << endl;
    }
    delete[] w;
}

Matrice_oarecare::~Matrice_oarecare()
{   Complex ** w=this->get_point();
    for (int i=0;i<this->lin;i++)
      {
        delete [] w[i];
      }



}
