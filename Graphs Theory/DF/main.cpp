#include <iostream>
#include <fstream>

using namespace std;

int tata[100], viz[100], n, a[100][100];

void df(int i)
{
    viz[i]=1;
    cout<<i<<" ";
    for(int j=1; j<=n ; j++)
        if(a[i][j]==1)
            if(viz[j]==0)
            {
                tata[j]=i;
                df(j);
            }
}

int main()
{
    int i, j;
    ifstream f("fis.in");
    f >> n ;
    for(i = 0 ; i < n ; i++ )
        {for(j = 0 ; j < n ; j++)
            a[i][j] = 0;
        viz[i] = 0;
        }
    while(!(f.eof()))
    {
        int x, y ;
        f >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    cout << "Parcurgerea in adancime: " << endl;
    for(i = 0 ; i < n ; i++ )
        {
            cout << endl << "Pentru nodul " << i+1 << ": ";
            df(i+1);
            for(j = 0 ; j < n ; j++ )
                viz[j] = 0;
            cout << endl;
            }
    return 0;
}
