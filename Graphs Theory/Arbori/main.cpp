#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int n, arbore_grad[50];

int cmp(int a, int b)
{
    return a < b;
}

int citire()
{
    ifstream f("fis.in");

    f >> n;
    int ok = 0, suma = 0;
    for(int i = 0 ; i < n ; i++)
        {
            f >>  arbore_grad[i];
            suma = suma + arbore_grad[i];
        }
    if( 2*(n - 1) != suma)
        {
            cout << endl << "Nu se poate construi arborele cu aceasta secventa de grade!" << endl;
            return 0;
        }
    sort(arbore_grad,arbore_grad+n, cmp);
    f.close();
    return 1;
}

void creare_arbore()
{
    cout << endl;
    int i, k, j;
    for( i = 0 ; i < n-1 ; i ++  )
        {
            int t = 0;
            for( j = i + 1 ; j < n ; j ++ )
                if( arbore_grad[i] < arbore_grad[j] )
                        {
                                while(arbore_grad[i] != 0 && arbore_grad[j] != 0)
                                    {
                                        cout << "Nodul " << i + 1 << " se uneste cu nodul " << j + 1 << endl;
                                        arbore_grad[i]--;
                                        arbore_grad[j]--;
                                    }
                        }
        }
    if(arbore_grad[n - 2] == 1 && arbore_grad[n -1] == 1)
        cout << "Nodul " << n - 1  << " se uneste cu nodul " << n << endl;

}

int main()
{
    if(citire() == 0 )
        return 0;
    creare_arbore();
    return 0;
}
