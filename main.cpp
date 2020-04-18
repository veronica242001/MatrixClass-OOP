#include "Complex.h"
#include "Matrice.h"
#include "Matrice_oarecare.h"
#include "Matrice_patratica.h"
#include <iostream>
#include<cstring>
using namespace std;

int main()
{
    try{
         Complex z(2,3),z1(1,0),z2;
         z2=z*z1;
         cout<<"produsul este:"<<z2<<"\n";



         Matrice_oarecare M;
         cin>>M;
         cout<<"Indici linie-coloana acceptati";
         cout<<M<<"\n";
         M.verif_diag();
         M.citire_afisare();
         ////////////////////

         Matrice_patratica M1;
           cin>>M1;
           cout<<M1<<"\n";
           M1.verif_diag();
         M1.citire_afisare();

         }
    catch (int x){ cout<<"Ati introdus linie negativa\n";}
    catch(double x){cout<<"Ati introdus colona negativa\n";}
    catch (char x){cout<<"Exceptie-indice negativ";}
    return 0;
}
