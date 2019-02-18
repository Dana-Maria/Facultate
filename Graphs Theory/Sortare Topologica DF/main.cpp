#include <iostream>
#include <fstream>
using namespace std;

/*  Sortarea topologica inseamna asezarea nodurilor astfel incat daca i este in stanga lui j, atunci exista arcul (ij)
   - sortarea topologica : 1 3 4 2 5 => nu pot exista arcele (3, 1), (4, 1) , (4, 3) ... dar exista cele inverse */

int a[100][100], n, m;
int vizitat[100];
int stiva[100], ultim = 1;

int sortare[100]; // aici vom retine de fapt sortarea topologica

void df(int i)
{
    vizitat[i] = 1;
    for (int j = 1; j <= n; j++)
    {
        if (a[i][j] == 1) // daca exista arcul (i, j)
            if (vizitat[j] == 0) // daca j este nevizitat
                df(j);
    }

    stiva[ultim] = i; // la final de tot il adaugam pe i in stiva
    ultim++; // marim dimensiunea stivei
}

void SortareTopologica()
{
    /* Urmatoarele 3 linii de cod se pot aplica si pentru a vedea daca un graf e conex sau pt a-i afisa comp conexe */
    for (int i = 1; i <= n; i++)
        if (vizitat[i] == 0) // pentru fiecare nod nevizitat bagam un df
            df(i);

    int nr = 1; // indicele pentru vectorul in care retinem sortarea topologica ( care va avea la final n elemente)
    while (ultim - 1 != 0) // scoatem din stiva pana cand ultimul ramane 0 (nu mai avem ce scoate )
    {
        int curent = stiva[ultim - 1]; // scoatem elementul din varful stivei
        ultim--; // stergem elementul extras din stiva

        sortare[nr] = curent; // il adaugam pe nodul curent in sortarea finala
        nr++; // marim capacitatea
    }
}

int main()
{
    ifstream f("fis.in");
    ofstream g("fis.out");

    f >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        f >> x >> y;
        a[x][y] = 1;
    }

    SortareTopologica();

    g << "Sortarea topologica: ";
    for (int i = 1; i <= n; i++)
        g << sortare[i] << " ";

    f.close();
    g.close();
    return 0;
}
