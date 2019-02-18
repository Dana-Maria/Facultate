#include <iostream>
#include <fstream>
#include <math.h>


//a) Se citeşte de la tastatură un număr natural N.
//Se consideră o tablă (matrice) pătratică de dimensiuni 2N*2N
//pe care se scriu numerele naturale de la 1 si 2N*2N prin vizitarea
//recursivă a celor patru cadrane ale tablei în ordinea indicată şi
//în figura alăturată: dreapta-sus, stânga-jos, stânga-sus, dreapta-jos.
//De exemplu, daca N=2, tabla este
//completată astfel:
//11 9 3 1
//10 12 2 4
//7 5 15 13
//6 8 14 16
using namespace std;
int n;
int v[100][100];
int x = 1;

void DI(int i_sus, int j_sus, int i_jos, int j_jos, int k)
{

    int i;
    if(k == 2)
    {
        v[i_sus][j_sus + 1] = x;
        v[i_jos][j_jos - 1] = x + 1;
        v[i_sus][j_sus] = x + 2;
        v[i_jos][j_jos] = x + 3;
        x = x + 4;
    }

    else
    {
        DI(i_sus, k/2 + j_sus, i_jos - k/2, j_jos, k/2);
        DI(k/2 + i_sus, j_sus, i_jos, j_jos - k/2,k/2);
        DI(i_sus, j_sus, i_jos - k/2, j_jos - k/2, k/2);
        DI(k/2 + i_sus , k/2 + j_sus, i_jos, j_jos, k/2);
    }

}
int main()
{

    ofstream g("fis.out");
    cout <<" Se da numarul: ";
    cin >> n;
    n = pow(2,n);

    DI(0, 0, n-1, n-1, n );

    for(int i = 0 ; i < n ; i++)
    {
            for(int j = 0; j < n ; j++)
                cout << v[i][j] << " ";
            cout << endl;

    }
    g.close();
    return 0;
}
