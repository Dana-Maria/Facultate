#include <iostream>
#include <limits>
#include <sstream>
#include <stdlib.h>
#include "claseeee.h"
using namespace std;

istream& operator>>(istream& in, Farmacie& f)
{
    string s;
    double p;
    string nr;
    int ang;


    cout << "Citeste denumire: ";
    getline(in, f.denumire);

    do
    {
        try
        {
            cout << "Citeste numarul de angajati: ";
            getline(in >> ws, nr);

            if (nr.find_first_not_of("0123456789") != string::npos)
                throw string("Numar invalid");

            ang = atoi(nr.c_str());
            break;
        }
        catch (string error)
        {
            cout << "A aparut o eroare: " << error << endl;
            continue;
        }
    } while(1);

    f.numar_angajati = ang;

    cout << "Citeste profitul pe toate lunile: " << endl;
    for(int i = 0 ; i < 12 ; i++ )
        {
            do
            {
                try
                {
                    cout << "Luna " << i+1 << ": " ;
                    getline(in >> ws, s);

                    if (s.find_first_not_of("0123456789.-") != string::npos)
                        throw string("Numar nevalid");

                    p = atof(s.c_str());
                    break;
                }

                catch (string error)
                {
                    cout << "A aparut o eroare: " << error << endl;
                    continue;
                }
            } while(1);

            f.profit[i] = p;
        }
    return in;
}

ostream& operator<<( ostream& on, const Farmacie& f )
{
    f.Afisare(on);
    return on;
}

const Farmacie& Farmacie :: operator=( const Farmacie& a)
{
    if(this != &a)
        {
            denumire = a.denumire;
            numar_angajati = a.numar_angajati;
            for(int i = 0 ; i < 12 ; i++ )
               profit[i] = a.profit[i];
       }
    return *this;
}

istream& operator>>(istream& in, Farmacie_Online& f)
{
    Farmacie far;
    in >> far;
    f.denumire = far.get_denumire();
    f.numar_angajati = far.get_numar_angajati();
    for(int i = 0 ; i < 12 ; i++ )
               f.profit[i] = far.get_profit(i);

    cout << "Adresa web: " ;
    getline(in >> ws, f.adresa_web);

    string s;
    do{
            try
            {
                cout << endl << "Numar vizitatori: ";
                getline(in >> ws, s);

                if(s.find_first_not_of("0123456789") != string::npos)
                    throw string("Caracter nevalid!");

                f.numarul_de_vizitatori = atoi(s.c_str());
                break;
            }
            catch(string Eroare)
            {
                cout << endl << "Eroare: " << Eroare << endl;
                continue;
            }

    }while(1);

    do
        {
            try
            {
                cout << endl << "Discountul utilizat: ";
                getline(in >> ws, s);

                if(s.find_first_not_of("1234567890.") != string::npos)
                    throw string("Caracter nevalid!");

                f.discountul_utilizat = atof(s.c_str());

                if( 0 > f.discountul_utilizat || 75 < f.discountul_utilizat )
                    throw string("Discount apartine intervalului [0,75]");
                break;
            }

            catch(string Eroare)
                {
                    cout << endl << "Eroare: " << Eroare << endl;
                    continue;
                }
        }while(1);

    cout << endl;
    return in ;
}
ostream& operator<<(ostream& on,const Farmacie_Online& f)
{
    f.Afisare(on);
    return on;
}

const Farmacie_Online& Farmacie_Online :: operator=( const Farmacie_Online& a )
{
    if(this != &a )
    {
        denumire = a.denumire;
        numar_angajati = a.numar_angajati;
        for(int i = 0 ; i < 12 ; i++ )
            profit[i] = a.profit[i];
        adresa_web = a.adresa_web;
        numarul_de_vizitatori = a.numarul_de_vizitatori;
        discountul_utilizat = a.discountul_utilizat;
    }
    return *this;
}

template <class T>
int GestionareFarmacie<T>::index = 0;

int main()
{
    int i, j;
    GestionareFarmacie<Farmacie> F(1);
    GestionareFarmacie<unsigned> U;

    int n;

    do {

        try
        {
            string s;

            cout << "Numarul de farmacii: ";
            getline(cin >> ws, s);

            if(s.find_first_not_of("1234567890") != string::npos)
                    throw string("Caracter nevalid!");
            n = atoi(s.c_str());

            if(n <= 0)
                throw string("Numar neacceptat!");

            break;
        }
        catch(string eroare)
        {
            cout << endl << "A aparut o eroare: " << eroare << endl;
            continue;
        }
    }while(1);

    i = 0;
    while( i < n )
    {
        do
        {
            try
            {
                string s;
                cout << endl << "1. Farmacie " << endl << "2. Farmacie Online" << endl;
                cout << "Alege optiune: ";
                getline(cin >> ws, s);

                if (s.find_first_not_of("0123456789") != string::npos)
                    throw string("Format nevalid al numarului");

                j = atoi(s.c_str());
                break;
            }
            catch (string eroare)
            {
                cout << endl << "A aparut o eroare: " << eroare << endl;
            }
        }while (1);

        cout << endl;
        switch(j)
            {
                case 1 :
                    {
                        cout << endl;
                        Farmacie* M = new Farmacie;
                        cin >> (*M);
                        F += (*M);
                        i++;
                        break;
                    }
                case 2 :
                    {
                        cout << endl;
                        Farmacie_Online* M = new Farmacie_Online;
                        cin >> (*M);
                        F += (*M);
                        U.set_nr(M->get_numarul_de_vizitatori() + U.get_nr());
                        i++;
                        break;
                    }
                default:
                    {
                        cout << "Optiune nevalida! Alege din nou optiunea!" << endl;
                    }
            }
    }
    vector<Farmacie*> v = F.get_vector();
    for(i = 0 ; i < v.size() ; i++ )
    {
        if(Farmacie_Online* N = dynamic_cast<Farmacie_Online*>(v[i]))
            {
                cout << endl << "Farmacie Online: " << (*N) << endl;
            }

        else
            if(Farmacie* N = dynamic_cast<Farmacie*>(v[i]))
            {
                cout << endl << "Farmacie: " << (*N) << endl;
            }
    }

    cout << U;
    return 0;
}
