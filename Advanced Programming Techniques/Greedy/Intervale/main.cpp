#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

struct interval
{
    int inceput, sfarsit;
};

int cmp(interval a, interval b)
{
    if(a.inceput > b.inceput)
        return 0;
    return 1;
}
int main()
{
    int a, b,i;
    ifstream f("fis.in");
    f >> a >> b;
    int numar;
    f >> numar;
    vector<interval> v;
    for( i = 0 ; i < numar ; i++)
    {
        interval m;
        f >> m.inceput >> m.sfarsit;
        v.push_back(m);
    }
    sort(v.begin(), v.end(), cmp);
//    for( i = 0 ; i < numar ; i++)
//        cout << v[i].inceput << " " << v[i].sfarsit << endl;
    int retine=0, nr = 0;
    while(b > a)
    {

        int maxx = 0;
        for(i = retine; i < numar ; i++)
            {
                if(v[i].inceput <= a)
                {
                    if(v[i].sfarsit > maxx)
                    {
                        maxx = v[i].sfarsit;

                    }
                }
            }

            if(maxx == 0)
            {
                cout << "Imposibil";
                return 0 ;

            }

            nr++;
            a = maxx;
    }

    cout << nr;
    return 0;
}
