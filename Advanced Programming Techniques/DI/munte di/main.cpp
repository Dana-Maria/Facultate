#include <iostream>
#include <fstream>

//Se dă un vector a=(a1,…an) de tip munte (există un indice i astfel încât a1<a2<…<ai > ai+1>…>an;
//ai se numeşte vârful muntelui). Propuneţi un algoritm O(log n)
//care determină vârful muntelui (în calculul complexităţii algoritmului nu se consideră şi citirea vectorului).

using namespace std;

int DI(int n, int v[], int pozitie)
{
    int i;
    int k = (pozitie + n)/2;
    if(v[k-1] < v[k] && v[k+1] < v[k])
        return k;
    if(v[k-1] < v[k] && v[k+1] > v[k])
        return DI(n, v, k);
    if(v[k-1] > v[k] && v[k+1] < v[k] )
        return DI(k, v, 0);
}
int main()
{
    int n;
    ifstream f("fis.in");
    f >> n;
    int i;
    int v[n];
    for(i = 0 ; i < n ; i++ )
    {
        f >> v[i];
    }

    int k = DI(n, v, 0);
    cout << "Varful muntelui: " << v[k];
    return 0;
}
