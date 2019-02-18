#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

struct cub
{
    int latura;
    int culoare;
    int poz;
};

int cmp(cub a, cub b)
{
    if(a.latura < b.latura)
        return 0;
    return 1;
}

int main()
{
    int numar, i;
    ifstream f("fis.in");
    f >> numar >> i;
    cub vec[numar], vec1[numar];

    for(i = 0 ; i < numar ; i++)
        {
            f >> vec[i].latura >> vec[i].culoare;
            vec[i].poz = i+1;

        }
    sort(vec, vec+numar, cmp);

//    for(i = 0 ; i < numar ; i++)
//        cout << vec[i].latura << " "<< vec[i].culoare << endl;

    int suma = 0, retine;
    suma = vec[0].latura;
    retine = vec[0].culoare;
    int k[numar];
    k[0] = vec[0].poz;
    int j = 1;
    for(i  = 1 ; i < numar ; i++)
    {
        if(vec[i].culoare != retine)
            {
                k[j] = vec[i].poz;
                j++;
                suma = suma + vec[i].latura;
                retine = vec[i].culoare;
            }
    }

    cout << "Suma= " << suma << endl << "Pozitiile:" << endl ;
    for(i = 0 ; i < j ; i++)
        cout << k[i] << " ";

    return 0;
}
