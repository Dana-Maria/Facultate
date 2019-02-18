#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Muchie
{
    int varf_i, varf_f;
    double cost;
};

void afis(int finall,int *tati, ofstream &g)
{
    if(tati[finall] == 0)
        g << " " << finall;
    else
    {
        afis(tati[finall], tati, g);
        g << " " << finall ;
    }

}

Muchie Muchie_minima( int m, Muchie *Muchii, int *vizitat ,int *distanta )
{
    Muchie m_minim = {0,0,0};
    int x, y;
    double cost_minim = 35000;
    for(int i = 0 ; i < m; i++ )
    {
        Muchie curent = Muchii[i];
        x = curent.varf_i;
        y = curent.varf_f;
        if((vizitat[x] == 0 && vizitat[y]==1) || (vizitat[x] == 1 && vizitat[y] ==0) )
//        if (vizitat[y] == 0)
            if(curent.cost + distanta[x] < cost_minim)
            {
                cost_minim = curent.cost + distanta[x];
                m_minim = curent;
            }
    }
    return m_minim;
}

void PRIM( int s, int n, int m,Muchie *muchii, ofstream &g , int finall)
{
    int ultimul, *vizitat, i, v;
    int distanta[n+1] = {35000};
    int tati[n+1] ={0};

    vizitat = new int[n+1];
    for(i = 1 ; i <= n ; i++)
        vizitat[i] = 0;
    vizitat[s] = 1;
    distanta[s] = 0;
    tati[s] = 0;

    for(i = 1 ; i < n ; i++)
    {

        Muchie minima = Muchie_minima(m, muchii, vizitat , distanta);
        distanta[minima.varf_f] = distanta[minima.varf_i] + minima.cost;
        tati[minima.varf_f] = minima.varf_i;
        vizitat[minima.varf_f] = 1;
        vizitat[minima.varf_i] = 1;

        cout << "Tati[" << minima.varf_f << "] = " << tati[minima.varf_f] << endl;
        cout << "Tati[" << minima.varf_i << "] = " << tati[minima.varf_i] << endl << endl;
    }
    for( i = 1; i < n ;i++ )
        cout << tati[i] << " ";
    afis(finall,tati,g);
}


int main()
{
    ifstream f("fis.in");
    ofstream g("fis.out");

    int n, m;

    f >> n >> m;

    int j, i, s ;

    Muchie *Muchii;
    Muchii = new Muchie[m];
    for(i = 0 ; i < m ; i++)
        f >> Muchii[i].varf_i >> Muchii[i].varf_f >> Muchii[i].cost;
    f.close();

    //vector <Muchie> Arb_Part_Cost_Min;

    do
    {
        cout << "Introduceti varful de start: ";
        cin >> s;
    }
    while( s > n );
    cout << "Dati nod final: ";
    int finall;
    cin >> finall;
    PRIM(s, n, m, Muchii,g, finall);
    g.close();
    return 0;
}
