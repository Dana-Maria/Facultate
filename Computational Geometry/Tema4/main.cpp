#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define PI 3.14159265

using namespace std;

struct punct
{
    int x, y, eticheta;
};

struct Vector
{
    int coordonata1, coordonata2;
};

vector<punct> puncte;

void Citire_Date()
{
    struct punct a;
    for(int i = 0 ; i <=3 ; i++)
    {
        cout << "A" << i+1 << ": " << endl <<"x=";
        cin>>a.x;
        cout<<"y=";
        cin>>a.y;
        cout << endl;
        a.eticheta = i;
        puncte.push_back(a);
    }
}

Vector converteste(punct a,punct b)
{
    Vector c;
    c.coordonata1 = b.x - a.x;
    c.coordonata2 = b.y - a.y;
    return c;
}

int produs_scalar(Vector a,Vector b)
{
    return a.coordonata1 * b.coordonata1 + a.coordonata2 * b.coordonata2;
}

float produs_module(Vector a,Vector b)
{
    int r = a.coordonata1 * a.coordonata1 + a.coordonata2 * a.coordonata2;
    int t = b.coordonata1 * b.coordonata1 + b.coordonata2 * b.coordonata2;
    return (sqrt(r))*(sqrt(t));
}

void punctul_a()
{
    cout << "Punctul a:" << endl;
    float Unghi_A2, Unghi_A4;
    Vector A2A3, A2A1;
    Vector A4A3, A4A1;

    A2A3 = converteste(puncte[1], puncte[2]);
    A2A1 = converteste(puncte[1], puncte[0]);
    A4A3 = converteste(puncte[3], puncte[2]);
    A4A1 = converteste(puncte[3], puncte[0]);

    Unghi_A2=acos((float)produs_scalar(A2A3, A2A1)/produs_module(A2A3, A2A1))*180.0/PI;
    Unghi_A4=acos((float)produs_scalar(A4A3, A4A1)/produs_module(A4A3, A4A1))*180.0/PI;

    cout<< "Unghi_A2: " <<Unghi_A2<<endl;
    cout<< "Unghi_A4: " << Unghi_A4<<endl;

    if(Unghi_A2 + Unghi_A4 < 181 && Unghi_A2 + Unghi_A4>179 )
        cout<<"Punctul A4 se afla pe cercul circumscris triunghiului A1A2A3";
    else
        if(Unghi_A2 + Unghi_A4 > 180)
            cout<<"Punctul A4 se afla in interiurul cercului circumscris triunghiului A1A2A3";
        else
            cout<<"Punctul A4 se afla in exteriorul cercului circumscris triunghiului A1A2A3";
    cout << endl;
}

float Distanta(punct a, punct b)
{
    int aa = (b.x-a.x)*(b.x-a.x);
    int bb = (b.y-a.y)*(b.y-a.y);
    return sqrt(aa + bb);
}

void punctul_b()
{
    cout << "Punctul b:" << endl;
    float distanta_1, distanta_2;
    distanta_1 = Distanta(puncte[0], puncte[1]) + Distanta(puncte[2], puncte[3]);
    distanta_2 = Distanta(puncte[1], puncte[2]) + Distanta(puncte[0], puncte[3]);
    if(distanta_1 == distanta_2) //distantele sunt egale
        cout<<"Patrulaterul format de punctele A1, A2, A3 si A4 este circumscriptibil.";
    else //distantele nu sunt egale
        cout<<"Patrulaterul format de punctele A1, A2, A3 si A4 nu este circumscriptibil.";
    cout << endl << endl;
}

int main()
{
    Citire_Date();
    punctul_a();
    cout<<endl;
    punctul_b();
    return 0;
}
