#include <iostream>
#include <fstream>

using namespace std;
/*
Se consideră o tablă de șah nxm (n,m date). Pe fiecare careul al tablei este plasat câte un obiect,
fiecare cu o anumită valoare (cunoscută, număr natural). Pe tablă se deplasează un robot astfel: pornește
de pe prima linie și prima coloană (un colț al tablei) și se poate deplasa numai în direcțiile sud și est.
La parcurgerea unei celule robotul adună obiectul din celulă. Să se determine un traseu al robotului până în poziția (n, m) (
până în colțul opus celui din care a plecat) astfel încât valoarea totală a obiectelor adunate să fie maximă.
Se vor afişa valoarea totală obţinută şi traseul optim O(nm)
*/
int n, m;
int a[100][100], b[100][100];

void afisare_matrice()
{
    int i, j;
    for( i = 0 ; i < n ; i++)
        {
            for( j = 0 ; j < m ; j++)
                cout << b[i][j] << " " ;
            cout << endl;
        }
}

int numar_mai_mare(int i, int j)
{

    if(a[i][j] + b[i-1][j] > a[i][j] + b[i][j-1])
        return a[i][j] + b[i-1][j];
    return a[i][j] + b[i][j-1];
}

int main()
{

    int i, j;
    // Citire de date
    ifstream f("fis.in");
    f >> n >> m;
    for( i = 0 ; i < n ; i++)
        for( j = 0 ; j < m ; j++)
                f >> a[i][j];
    f.close();

    b[0][0] =  a[0][0];
    for( i = 1 ; i < n ; i++ )
        b[0][i] = a[0][i] + b[0][i-1];

    for(i = 1 ; i < n ; i++)
        for( j = 0 ; j < m ; j++)
            {
                if( j == 0)
                        b[i][j] = a[i][j] + b[i-1][j];

                else
                {
                    int ok = numar_mai_mare(i,j);
                    b[i][j] = ok;

                }
            }
    int maxim = b[n-1][m-1];
    cout << "Numarul cel mai din dreapta: " << maxim << endl;
    cout << "Drumul urmat: " << endl;
    cout << "(" << 1 << ", " << 1 << ")" << endl;
    int t = 0;
    for( i = 1 ; i < n ; i++ )
        if( b[0][i] > b[1][i] )
            cout << "(" << i + 1 << ", " << j + 1 << ")" << endl;
        else
            t = 1;
    if(t == 1)
        if(b[0][1] > b[1][0])
            cout << "(" <<  1 << ", " << 2 << ")" << endl;
        else
            cout << "(" <<  2 << ", " << 1 << ")" << endl;
    for(i = 1 ; i < n ; i++)
        for(j = 0 ; j < m ; j++)
        {
            if( j == 0 && b[i][0] > b[i][1])
                cout << "(" << i + 1 << ", " << j + 1 << ")" << endl;
                else
                    if( j != 0 && j != m - 1 && b[i][j] > b[i][j-1] && b[i][j] > b[i-1][j])
                        cout << "(" << i + 1 << ", " << j + 1 << ")" << endl;
                    else
                        if( j == m - 1 && b[j][m-1] > b[j-1][m-1] && b[j][m-1] > b[j-1][m-1] &&
                           b[j][m-1] < b[j+1][m-2] )
                                cout << "(" << i + 1 << ", " << j + 1 << ")" << endl;
                        else
                            if(j == m-1 && i == n-1)
                                cout << "(" << i + 1 << ", " << j + 1 << ")" << endl;
        }
    return 0;
}
