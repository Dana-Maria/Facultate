#include <iostream>

using namespace std;

struct punct
{
    double x, y, z;
};

int main()
{
    punct a1, a2, a3;
    double a;
    cout << "Sa se citeasca A1: " << endl;
    cin >> a1.x >> a1.y >> a1.z;
    cout << "Sa se citeasca A2: " << endl;
    cin >> a2.x >> a2.y >> a2.z;
    cout << "Sa se citeasca A3: " << endl;
    cin >> a3.x >> a3.y >> a3.z;

    //Cazul 1

    if(a1.x == a2.x && a1.y == a2.y && a1.z == a2.z)
    {
        cout << "A1 si A2 coincid. A3 = 1*A2 + 0*A3 ";
    }
    else
    {
        //Cazul 2
        if((a2.y - a1.y) != 0)
        {
            a = (a3.y - a1.y)/(a2.y - a1.y);
            if(a3.x-a1.x == a*(a2.x - a1.x) && a3.z-a1.z == a*(a2.z - a1.z) )
            cout << "a=" << a << endl <<"A3 =("  << 1 - a <<")*A1 + " << a <<"*A2";
            else
                cout << "Nu sunt coliniare";
        }
        else
        {
            if((a2.x - a1.x) != 0)
            {
                a = (a3.x - a1.x)/(a2.x - a1.x);
                if(a3.y-a1.y == a*(a2.y - a1.y) && a3.z-a1.z == a*(a2.z - a1.z) )
                    cout << "a=" << a << endl <<"A3 =("  << 1 - a <<")*A1 + " << a <<"*A2";
                else
                    cout << "Nu sunt coliniare";
            }
            else
                if((a2.z - a1.z) != 0)
                    {
                        a = (a3.z - a1.z)/(a2.z - a1.z);
                        if(a3.y-a1.y == a*(a2.y - a1.y) && a3.x-a1.x == a*(a2.x - a1.x) )
                            cout << "a=" << a << endl << "A3 =("  << 1 - a <<")*A1 + " << a <<" * A2";
                    }
                else
                    cout << "Nu se poate";

        }
    }

    return 0;
}
