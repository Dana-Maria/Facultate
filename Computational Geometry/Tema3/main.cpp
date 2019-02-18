#include <iostream>

using namespace std;

struct  punct
{
    double x, y;
};

int apartine(double x, double y, punct a, punct b )
{
    double min1, min2, max1, max2;
    if(a.x > b.x)
    {
        min1 = b.x;
        max1 = a.x;
    }
    else
    {
        max1 = b.x;
        min1 = a.x;
    }

    if(a.y > b.y)
    {
        min2 = b.y;
        max2 = a.y;
    }
    else
    {
        max2 = b.y;
        min2= a.y;
    }
    return (x >= min1 && x <= max1 && y >= min2 && y <= max2);
}
int main()
{
    punct a1, a2, a3, a4;
    int i;

    cout << "Sa se citeasca A1: " <<endl << "X= ";
    cin >> a1.x;
    cout << "Y= ";
    cin >> a1.y;

    cout << "Sa se citeasca A2: " <<endl << "X= ";
    cin >> a2.x;
    cout << "Y= ";
    cin >> a2.y;

    cout << "Sa se citeasca A3: " <<endl << "X= ";
    cin >> a3.x;
    cout << "Y= ";
    cin >> a3.y;

    cout << "Sa se citeasca A4: " <<endl << "X= ";
    cin >> a4.x;
    cout << "Y= ";
    cin >> a4.y;

    double  a_1, a_2, b1, b2, c1, c2, X, Y, D;

    a_1 = a2.y - a1.y;
    b1 = a1.x - a2.x;
    c1 = a2.x * a1.y - a1.x * a2.y;

    a_2 = a4.y - a3.y;
    b2 = a3.x - a4.x;
    c2 = a4.x * a3.y - a3.x * a4.y;

    D = b2 * a_1 - b1 * a_2;
    if(D != 0)
    {
        X = ((-c1) * b2 - (-c2) * b1)/D;
        Y = (a_1 * (-c2) - a_2 * (-c1))/D;
        if(apartine(X,Y,a1,a2) && apartine(X,Y,a3,a4))
            cout << "\nSegmentele se intersecteaza in punctul: (" << X << ", " << Y << "); \n";
        else
            cout <<"Dreptele se intersecteaza in punctul: (" << X << ", " << Y << "); \n";
    }
    else
    {
        double rr;
        rr = a_1 * c2 - a_2 * c1;
        if( rr != 0 )
            cout <<"Nu se intersecteaza";
        else
            cout << "A1A2 = A3A4";
    }

    return 0;
}
