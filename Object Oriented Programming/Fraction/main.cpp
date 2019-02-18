#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

class Fractie {

    int numitor, numarator;

    public:

        Fractie();//constructor de initializare
        Fractie(int, int);//constructor de initializare cu parametri
        Fractie (const Fractie&);//constructor de copiere
        ~Fractie();
        int get_numitor(){ return numitor; }
        void set_numitor(int x){ numitor = x; }
        int get_numarator() { return numarator; }
        void set_numarator(int y) { numarator = y; }
        void simplifica();
        void afisare();
        friend istream &operator>>(istream &, Fractie&);
        Fractie operator+(Fractie&);
        Fractie operator-(Fractie&);
        Fractie operator/(Fractie&);
        Fractie operator*(Fractie&);
        Fractie operator*(int);
};

Fractie ::Fractie()
{
    numitor = 1;
    numarator = 0;
}

istream &operator>>(istream &a, Fractie &b)
{
    int x;
    cout << "Dati numarator: ";
    a >> x;
    b.numarator = x;
    do{
        cout << "Dati numitor: ";
        a >> x;
    }while(x == 0);
    b.numitor = x;
    b.simplifica();
}

Fractie ::Fractie(int x , int y)
{
    numitor = y;
    numarator = x;
    simplifica();
}

Fractie::Fractie(const Fractie& f)
{
    numitor=f.numitor;
    numarator=f.numarator;
}

Fractie ::~Fractie()
{
    cout << "D "  ;
}

int CMMDC(int x, int y)
{
    while(x != y)
        if(x > y)
            x = x - y;
        else
            y = y - x;
    return x;
}

int CMMMC(int x, int y)
{
    return (x * y)/CMMDC(x,y);
}


void Fractie::simplifica()
{
    if(numarator == 0)
        return;
    int s;
    int x, y;
    x = abs(numarator);
    y = abs(numitor);
    s = CMMDC(x, y);
    while( x % s == 0 && y % s == 0 )
    {
        numarator = numarator / s;
        numitor = numitor / s;
         x = abs(numarator);
        y = abs(numitor);
        s = CMMDC(x, y);
        if(s == 1)
            break;
    }
}

void Fractie::afisare()
{
    if(numarator == 0)
        cout << "0" ;
    else
        if( numitor == 1 )
                cout << numarator;
        else
            if( numitor > 0 && numarator > 0 )
                cout << numarator << "/" << numitor ;
            else
                if( (numitor > 0 && numarator < 0) ||  (numitor < 0 && numarator > 0))
                    cout << "-" << abs(numarator) << "/" << abs(numitor) ;
                else
                {
                    numitor = abs (numitor);
                    numarator = abs (numarator);
                    cout << numarator << "/" << numitor ;
                }
                cout << endl;
}

Fractie Fractie::operator+(Fractie& c)
{
    Fractie b(0,1);
    if(numitor == c.get_numitor())
    {
        b.set_numarator(numarator+c.get_numarator());
        b.set_numitor(numitor);
        b.simplifica();
        return b;
    }
    b.set_numarator(numarator*c.get_numitor()+numitor* c.get_numarator());
    b.set_numitor(numitor*c.get_numitor());
    b.simplifica();
    return b;
}

Fractie Fractie::operator-(Fractie& c)
{
    Fractie b(0,1);
    if(numitor == c.get_numitor())
    {
        b.set_numarator(numarator-c.get_numarator());
        b.set_numitor(numitor);
        b.simplifica();
        return b;
    }
    b.set_numarator(numarator*c.get_numitor()-numitor* c.get_numarator());
    b.set_numitor(numitor*c.get_numitor());
    b.simplifica();
    return b;
}

Fractie Fractie::operator*(Fractie& c)
{
    Fractie b (0,1);
    b.set_numarator(numarator*c.get_numarator());
    b.set_numitor(numitor*c.get_numitor());
    b.simplifica();
    return b;
}

Fractie Fractie::operator*(int c)
{
    Fractie b (0,1);
    b.set_numarator(numarator*c);
    b.set_numitor(numitor);
    b.simplifica();
    return b;
}

Fractie Fractie::operator/(Fractie& c)
{
    Fractie b (0,1);
    b.set_numarator(numarator*c.get_numitor());
    b.set_numitor(numitor*c.get_numarator());
    b.simplifica();
    return b;
}

void Rezolva_Ecuatie()
{
    cout << endl << "Predefinit:\nelementul x o sa fie in prima fractie\nelementul y o sa fie in a doua fractie \n" << endl;
    Fractie x, y;
    Fractie v[6];
    int i, j = 1;
    for ( i = 0 ; i < 6 ; i ++ )
        {
            if( i == 2 || i == 5)
            {
                cout << "Introduceti rezultatul(" << j << ") fractie: " << endl ;
                cin >> v[i];
                j++;
            }
            else
            {
                cout << "Introduceti a " << i+1 << "-a fractie: " << endl ;
                cin >> v[i];
            }
            cout <<endl;
        }
    int kk=0, kkk = 0, u = 2;
    i = CMMMC(v[0].get_numitor(), v[1].get_numitor());
    while(u < 6)
        {
            i = CMMMC(i,v[u].get_numitor());
            u ++ ;
        }
    j = 0;
    while(j < 6)
    {
        int nnume = i/v[j].get_numitor();
        v[j].set_numarator(v[j].get_numarator() * nnume);
        v[j].set_numitor(1);
        j++;
    }
    if( v[0].get_numarator() == v[3].get_numarator() )
        kk = 1;
    else
        if( (v[0].get_numarator() == -v[3].get_numarator()))
            kk = 2;
        else
            {
                int v1, v2;
                v2 = v[0].get_numarator();
                v1 = v[3].get_numarator();
                //cout << v1 << " " << v2 << endl;
                for( i = 0 ; i < 6 ; i++ )
                    if(i < 3)
                        v[i].set_numarator(v[i].get_numarator() * v1);
                    else
                        v[i].set_numarator(v[i].get_numarator() * v2);
                if( v[0].get_numarator() == v[3].get_numarator() )
                    kk = 1;
                else
                    if( (v[0].get_numarator() == -v[3].get_numarator()))
                        kk = 2;
            }
        if( kk == 1)
            {
                for( i = 0 ; i < 3 ; i ++ )
                    v[i]= v[i] - v[i+3];
                y = v[2]/v[1];
                Fractie f = y * v[4];
                x = v[5] - f;
                x = x/v[3];
            }
        else
        {
            for( i = 0 ; i < 3 ; i ++ )
                    v[i]= v[i] + v[i+3];
                y = v[2] / v[1];
                Fractie f = y*v[4];
                x = v[5] - f;
                x = x/v[3];
        }
        cout << endl << "x=";
        x.afisare();
        cout << endl <<  "y=";
        y.afisare();
}
void meniu()
{
    cout << endl;
    cout << "1. Adunarea a doua fractii" << endl;
    cout << "2. Scaderea a doua fractii" << endl;
    cout << "3. Produsul a doua fractii" << endl;
    cout << "4. Produsul unei fractii cu un numar intreg" << endl;
    cout << "5. Raportul a doua fractii" << endl;
    cout << "6. Sistem de doua ecuatii" << endl;
    cout << "0. Exit!" << endl << endl;
}

int main()
{
      Fractie f1, f2;
      int x, y;
      meniu();
      int optiune;
      cout << "Alege optiune: ";
      cin >> optiune;
      while(optiune != 0)
      {
          switch (optiune)
          {
                case 1:
                    cout << endl;
                    cout << "Introduceti prima fractie: " << endl ;
                    cin >> f1;
                    cout << endl <<"Introduceti a doua fractie: " << endl;
                    cin >> f2;
                    cout << endl << "Rezultat: ";
                    (f1+f2).afisare();
                    cout << endl;
                    break;

                case 2:
                    cout << endl;
                    cout << "Introduceti prima fractie: " << endl ;
                    cin >> f1;
                    cout << endl << "Introduceti a doua fractie: " << endl;
                    cin >> f2;
                    cout << endl << "Rezultat: ";
                    (f1-f2).afisare();
                    cout << endl;
                    break;

                case 3:
                    cout << endl;
                    cout << "Introduceti prima fractie: " << endl ;
                    cin >> f1;
                    cout << endl << "Introduceti a doua fractie: " << endl;
                    cin >> f2;
                    cout << endl << "Rezultat: ";
                    (f1*f2).afisare();
                    cout << endl;
                    break;

                case 4:
                    cout << endl;
                    cout << "Introduceti fractie: " << endl ;
                    cin >> f1;
                    cout << "Numarul intreg: ";
                    cin >> x;
                    (f1*x).afisare();
                    cout << endl;
                    break;

                case 5:
                    cout << endl;
                    cout << "Introduceti prima fractie: " << endl ;
                    cin >> f1;
                    cout << endl << "Introduceti a doua fractie: " << endl;
                    cin >> f2;
                    cout << endl << "Rezultat: ";
                    (f1/f2).afisare();
                    cout << endl;
                    break;

                case 6:
                    Rezolva_Ecuatie();
                    cout << endl;
                    break;
          }
          meniu();
          cout << "Alege optiune: ";
          cin >> optiune;
      }
      return 0;
}

