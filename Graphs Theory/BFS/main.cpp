#include <iostream>
#include <fstream>
using namespace std;

int a[100][100], n, m;

void bf(int start)
{
    int vizitat[n + 1] = {0};
    int prim, ultim; // prim si ultim reprezinta prima, respectiv ultima pozitie din coada
    prim = ultim = 1; // la inceput coada este goala, deci prima pozitia este egala cu ultima pozitie (=1)

    int c[n + 1]; // coada
    c[ultim] = start; // adaugam nodul de inceput in coada
    vizitat[start] = 1; // marcam nodul de start ca vizitat
    cout << start << " ";

    while (prim <= ultim) // conditia care ne spune daca coada este vida sau nu ( este vida cand prim > ultim )
    {
        int curent = c[prim]; // extragem primul nod din coada si ii vom cauta vecinii nevizitati
        for (int i = 1; i <= n; i++) // parcurgem toate nodurile grafului
        {
            if (a[curent][i] == 1) // daca i este vecin al nodului curent
                if (vizitat[i] == 0) // daca i este un vecin nevizitat al nodului curent
                {
                    ultim++; // marim coada
                    c[ultim] = i; // il adaugam pe i in coada
                    vizitat[i] = 1; // il marcam pe i ca vizitat

                    cout << i << " ";
                }
        }
        prim++; // trecem la urmatoarea pozitie in coada (adica ignoram elementele deja parcurse ca sa nu le parcurgem iar)
    }

    cout << endl;
}

int main()
{
    ifstream f("fis.in");
    f >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        f >> x >> y;
        a[x][y] = a[y][x] = 1;
    }

    int start;
    cout << "Introduceti nodul de start: ";
    cin >> start;

    bf(start);

    f.close();
    return 0;
}
