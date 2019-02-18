#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Muchie
{
    int varf_i, varf_f;
    double cost;
};

Muchie Muchie_minima( int m, Muchie *Muchii, int *vizitat )
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
            if(curent.cost < cost_minim)
            {
                cost_minim = curent.cost;
                m_minim = curent;
            }
    }
    return m_minim;
}

void PRIM( int s, int n, int m,Muchie *muchii, vector <Muchie>& arbore_partial_de_cost_minim )
{
    int *vizitat, i, v;
    vizitat = new int[n+1];
    for(i = 1 ; i <= n ; i++)
        vizitat[i] = 0;
    vizitat[s] = 1;
    for(i = 1 ; i < n ; i++)
    {
        Muchie minima = Muchie_minima(m, muchii, vizitat);
        arbore_partial_de_cost_minim.push_back(minima);
        vizitat[minima.varf_f] = 1;
        vizitat[minima.varf_i] = 1;
    }
}

void afis(Muchie m, ofstream &g)
{
    g << "(" << m.varf_i<< ", " << m.varf_f << ") cost " << m.cost<<endl;
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

    vector <Muchie> Arb_Part_Cost_Min;
    PRIM(s, n, m, Muchii, Arb_Part_Cost_Min);
    if(Arb_Part_Cost_Min.size() < n-1)
    {
        cout << "Graf neconex";
        return 0;
    }
    else
    {
        double cost = 0;
        for( i = 0 ; i < Arb_Part_Cost_Min.size() ; i++)
        {
            afis(Arb_Part_Cost_Min[i],g);
            cost = cost + Arb_Part_Cost_Min[i].cost;
        }
        g << "Costul: " << cost;
    }
    g.close();
    return 0;
}
