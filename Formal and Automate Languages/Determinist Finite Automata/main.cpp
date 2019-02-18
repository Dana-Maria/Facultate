#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;
int verifica(string nume, string *alfabet, int numar_litere)
{
    if(nume == "*")
        return 1;

    int i, numara = 0, ok = nume.length();
    for(i = 0; i < numar_litere ; i++)
    {
        int j = 0;
        while(j < ok)
        {
            if(nume[j] == '+' )
            {
                j++;
            }
            for(int k = 0 ; k < alfabet[i].size() ; k++)
            {
                if(nume[j] == '+' )
                {
                    j++;
                }

                if(nume[j] == alfabet [i][k] )
                {
                    numara++;
                    j++;
                }
                else
                {
                    j++;
                    break;
                }
            }
        }
    }
    if(numara == ok)
        return 1;
    else
        return 0;
}

int main()
{
    ifstream f("X.in");
    int i, j, ok = 1;
    int numar_noduri, numar_litere;

    f >> numar_noduri;
    string matrice[numar_noduri][numar_noduri];

    f >> numar_litere;
    string alfabet[numar_litere+1];

    for (i = 0 ; i < numar_litere ; i++)
        f >> alfabet[i];

    int stare[numar_noduri];

    for(i = 0 ; i < numar_noduri ; i++)
        stare[i]=0;

    int stare_initiala;

    f >> stare_initiala;
    stare[stare_initiala] = 1;

    int numar_stari_finale;
    f >> numar_stari_finale;

    for (i = 0; i < numar_stari_finale; i++)
    {
        int stare_finala;
        f >> stare_finala;
        stare[stare_finala] = -1;
    }

    int numar_tranzitii;
    f >> numar_tranzitii;

    for (i = 0 ; i < numar_noduri ; i++ )
        for( j = 0 ; j <numar_noduri ; j++)
            matrice[i][j] = "*";
    for( i= 0 ; i < numar_tranzitii; i++)
    {
        int v,x;
        string variabila;
        f >> v >> variabila >> x;

        if (verifica(variabila,alfabet,numar_litere) == 0 )
        {
            cout << "Caracter " << variabila << " nu apartine alfabetului ";
            return 0;
        }

        if(matrice[v][x] == "*")
            matrice[v][x] = variabila;
        else
            matrice[v][x].append(variabila);
    }
    cout << "O sa se verifice daca urmatorul cuvant apartine sau nu limbajului recunoscut de automat: ";
    string cuvant;
    cin >> cuvant;
    cout << endl ;

    int poz;
    for( i = 0 ; i < numar_noduri ; i++ )
        if(stare[i] == 1)
            poz = i;

    if(cuvant == "#")
    {
        for( i = 0; i < numar_noduri ; i++ )
            if( stare[stare_initiala] == -1 )
            {
                cout << "Cuvantul a fost acceptat de aparat!";
                cout << endl ;
                return 0;
            }
    }
    i = 0;
    while(!cuvant.empty())
    {
        ok = 0;
        for( j = 0; j < numar_noduri ; j++)
        {
            string nume=matrice[poz][j];

            if(nume.size()>=2)
            {

                int nu = nume.size(), l;
                string copie;
                copie.insert(0,nume);
                if(verifica(copie, alfabet, nu) == 0)
                {
                    cout << copie << " ";
                    cout << "Cuvantul nu este acceptat de aparatul dat!";
                    cout << endl ;
                    return 0;
                }
                for(l = 0; l < nu ; l++)
                {
                    if( cuvant.find(copie[l]) == 0 )
                    {
                        poz = j;
                        ok = 1;
                        cuvant.erase(0, nume.size());
                        break;
                    }
                }
            }
            if( cuvant.find(nume) == 0 )
            {
                poz = j;
                ok = 1;
                cuvant.erase(0, nume.size());
                break;
            }
        }
        if(ok == 0)
        {
            cout << "Cuvantul nu este acceptat de aparat dat!";
            cout << endl ;
            return 0;
        }
    }
    for( i = 0; i < numar_noduri ; i++ )
        if( stare[i] == -1 )
            if(poz == i)
            {
                cout << "Cuvantul a fost acceptat de aparat!";
                cout << endl ;
                return 0;
            }
    cout << "Cuvantul nu este acceptat de aparat si nu a ajuns intr-o stare finala!";
    cout << endl ;
    return 0;
}


