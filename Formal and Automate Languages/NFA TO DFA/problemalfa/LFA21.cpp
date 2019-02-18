#include <bits/stdc++.h>
#include <sstream>
using namespace std;

string IntToString (int a)
{
    ostringstream temp;
    temp << a;
    return temp.str();
}
string matrice[50][50];

string parcurgere_df(int x, string caracteristica,int numar_noduri)
{
    int i;
    string kk = "" ;
    for ( i = 0 ; i < numar_noduri ; i++ )
        if(matrice[x][i] != "*")
            if(matrice[x][i].find(caracteristica) != string::npos )
            {
                char *sir;
                sir = new char[259];
                itoa(i, sir, 10);
                string k(sir);
                kk = kk + k ;
                delete[] sir;
            }
    if(kk != "")
        return kk;
    else
        return string("*");
}

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

int st[256];

void retine(vector<string>& s, int n)
{
    string aux_s = "";
    for (int i = 0; i < n; i++)
    {
        char w[256];
        itoa(st[i], w, 10);
        aux_s = aux_s + w;
    }

    s.push_back(aux_s);

}

bool bktr_valid(int k)
{
    if (k == 0)
      return true;
    if (k == 1)
        if (st[0] >= st[1])
          return false;
        else
            return true;

    for (int i = 0; i < k; i++)
        if (st[i] >= st[i+1])
            return false;

    return true;
}

void bktr (int k, vector<string>& s, int n, int m)
{
    if (k == n)
        retine(s, n);
    else
    {
       for (int i = 0; i < m; i++)
       {
           st[k] = i;
           if (bktr_valid(k))
              bktr(k+1, s, n, m);
       }
    }
}

int main()
{
    ifstream f("date.in");
    ofstream g("date.out");

    int i, j, ok = 1;
    int numar_noduri, numar_litere;

    f >> numar_noduri;

    f >> numar_litere;
    string alfabet[numar_litere+1];

    for (i = 0 ; i < numar_litere ; i++)
        f >> alfabet[i];

    int stare[50] = {0};

    int stare_initiala;

    f >> stare_initiala;
    stare[stare_initiala] = 1;

    int numar_stari_finale;
    f >> numar_stari_finale;
    g << "Stari finale(AFN):" << endl;
    for (i = 0 ; i < numar_stari_finale ; i++)
    {
        int stare_finala;
        f >> stare_finala;
        stare[stare_finala] = -1;
        g << stare_finala << " ";
    }

    int numar_tranzitii;
    f >> numar_tranzitii;

    for (i = 0 ; i < numar_noduri ; i++ )
        for( j = 0 ; j < numar_noduri ; j++)
            matrice[i][j] = "*";
    g << endl << endl << "Stari(AFN): " << endl;
    for( i = 0 ; i < numar_tranzitii; i ++)
    {
        int v, x;
        string variabila;
        f >> v >> variabila >> x;

        if (verifica(variabila, alfabet, numar_litere) == 0 )
        {
            cout << "Caracter " << variabila << " nu apartine alfabetului ";
            return 0;
        }
        g << v << " ajunge cu ( " << variabila << " ) la " << x << endl;
        if(matrice[v][x] == "*")
            matrice[v][x] = variabila;
        else
            matrice[v][x].append(variabila);
    }
    g << endl << "Matricea(AFN)" << endl;
    for (i = 0 ; i < numar_noduri ; i++ )
        {
            for( j = 0 ; j < numar_noduri ; j++)
                g << matrice[i][j] << " ";
            g << endl;
        }
    int n = pow (2.0, numar_noduri);
    int m = numar_litere ;
    string new_matrice[n][m];
    vector<string> new_noduri;

    for(int k = 0 ; k < numar_noduri ; k ++)
        {
            char st[256];
            itoa(k, st, 10);
            string aux(st);
            new_noduri.push_back(aux);
        }
     for (i = 2; i <= numar_noduri; i++)
            bktr(0, new_noduri, i, numar_noduri);

    for( i = 0; i < n; i++)
        for(j = 0; j < m ; j++)
            new_matrice[i][j] = "";

    int k;

    for(i = 0 ; i < numar_litere ; i++)
       {
           for( j = 0 ; j < numar_noduri ; j++ )
                new_matrice[j][i] = parcurgere_df(j, alfabet[i], numar_noduri);
        }

    for( i = 0 ; i < numar_litere ; i++)
    {
        for(j = numar_noduri ; j < new_noduri.size(); j++)
        {
            string ok = "*";
            for(k = 0 ; k < new_noduri[j].size() ; k++)
                {
                    string t = "";
                    t = parcurgere_df(new_noduri[j][k] - '0', alfabet[i], numar_noduri);
                    if(ok == "*" )
                        ok = t;
                    else
                        if(t != "*")
                        ok = ok + t;
                    sort(ok.begin(), ok.end());

                    for(int tt = 0; tt < ok.size() - 1; tt++)
                        if( ok[tt] == ok[tt + 1] )
                    {
                         ok.erase(tt, 1);
                    }
                    new_matrice[j][i] = ok;
                }
        }
    }

    int elemente_stari_finale = 0;
    i = 0;
    while(i < numar_noduri)
    if(stare[i] != -1)
        i++;
    else
        {
            for(j = numar_noduri ; j < new_noduri.size() ; j++)
                if(new_noduri[j].find(IntToString(i)) != string::npos  )
                    {
                        stare[j] = -1;
                        elemente_stari_finale++;
                    }
            i ++;
        }

    elemente_stari_finale = numar_noduri + elemente_stari_finale;

    for(i = 0 ; i < new_noduri.size(); i++)
        for(j = 0 ; j < new_noduri.size(); j++)
            matrice[i][j] = "*";

    n = new_noduri.size();
    // Matrice AFD
    for( i = 0 ; i < n ; i++ )
        for( j = 0 ; j < m ; j++ )
    {
        if(new_matrice[i][j] != "*")
        {
            for( int y = 0 ; y < n ; y++ )
                if(new_noduri[y] == new_matrice[i][j])
                    if(matrice[i][y] == "*")
                        {
                            matrice[i][y] = alfabet[j];
                            break;
                        }
                else

                    if(matrice[i][y] != alfabet[j])
                            matrice[i][y].append(alfabet[j]);
        }
    }

    // Afisare AFD

    g << endl << "------*------" << endl ;
    g << endl << "Numar stari(AFD): ";
    g << new_noduri.size() << endl;
    g << endl << "Numar litere alfabet(AFD): " << numar_litere << endl ;
    for(i = 0 ; i < numar_litere ; i++)
        g << alfabet[i] << " ";

    g << endl << endl;
    g << "Matrice(AFD): " << endl;

    for( i = 0; i < n; i++)
        {
            for( j = 0; j < n ; j++)
                g << matrice[i][j] << " ";
            g << endl;
        }
    int u = 0;

    g << endl;
    vector <int> sarite; // in vectorul asta retinem starile pe care nu le-am inclus in automatul final

    for (i = 0; i < n; i++)
    {
        /* Aici adaugam in vectorul de sarite toate starile cu * pe coloana, pe care nu le consideram ca facand parte din automat */
        int suma = 0;
        for (j = 0; j < n; j++)
            if( matrice[j][i] == "*")
                suma++;
            else if (matrice[j][i] != "*" && j == i)
                suma++;
        if (suma == n && i != stare_initiala)
            sarite.push_back(i);
    }
    for( i = 0; i < n; i++)
        {
            int suma = 0;
            for( j = 0; j < n ; j++)
                {
                    /*  Aici mai verificam o data acea suma de stelute, dar adaugam conditia ca o tranzitie sa fie valida daca nu pleaca dintr-o
                    stare deja sarita */
                    if( matrice[j][i] == "*")
                        suma++;
                    else if (matrice[j][i] != "*" && j == i)
                        suma++;
                    else if (matrice[j][i] != "*" && find(sarite.begin(), sarite.end(), j) != sarite.end())
                        suma++; // daca tranzitia pleaca dintr-o stare deja sarita, o ignoram
                }
            if(suma < n || i == stare_initiala)
                    {

                        for( j = 0; j < n ; j++)
                            if(matrice[i][j] != "*")
                                    {
                                        g << new_noduri[i] << " ajunge cu ( " << matrice[i][j] <<" ) la " << new_noduri[j] << endl;
                                        u ++;
                                    }
                            else
                                if( i == j)
                                    continue;
                    }

            else
                sarite.push_back(i);
        }

    g << endl << "Numar tranzitii(AFD): " << u ;

    g << endl << endl << "Stari(AFD): " ;
    for (int i = 0; i < new_noduri.size(); i++)
        if (find(sarite.begin(), sarite.end(), i) == sarite.end())
            g << new_noduri[i] << " ";
    g << endl;

    g << endl  << "Stare initiala(AFD): " << stare_initiala <<endl;

    g << endl  << "Stari finale(AFD): " ;
    int tttt = 0;
    for(i = 0 ; i < n ; i++)
        if(stare[i] == -1 && find(sarite.begin(), sarite.end(), i) == sarite.end())
            tttt++; // aflam numarul de stari finale din automatul dfa
    g << tttt << endl;
    for(i = 0 ; i < n ; i++)
        if(stare[i] == -1 && find(sarite.begin(), sarite.end(), i) == sarite.end())
            g << new_noduri[i] << " " ; // afisam starile finale din dfa

    f.close();
    g.close();
    return 0;
}
