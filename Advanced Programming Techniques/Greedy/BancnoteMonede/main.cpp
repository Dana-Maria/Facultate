#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int cmp(int a, int b)
{
    if(a < b)
        return 0;
    return 1;
}
int main()
{
    int numar, suma, r, c,i;
    ifstream f("fist.in");
    f >> numar;
    int vec[numar];
    for( i = 0 ; i < numar ; i++)
        f >> vec[i];
    f >> suma;

    sort(vec, vec+numar, cmp);

    for(i = 0 ; i < numar ; i++)
    {
        c = suma/vec[i];
        if(c == 0)
            continue;

        cout << c << "*" << vec[i] << endl;
        r = suma%vec[i];
        if(r == 0)
            break;
        suma = r;
    }
    return 0;
}
