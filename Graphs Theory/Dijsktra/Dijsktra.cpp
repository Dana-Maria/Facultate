#include <fstream>
#include <iostream>
#include <algorithm>
#define infinit INT_MAX

using namespace std;

struct muchie
{
    int vi, vf;
    double cost;
};

int minim(double *distanta, int *viz, int n)
{
    int u = -1;
    double distanta_min = infinit;
    for(int i=1 ; i<=n ; i++)
        if(viz[i] == 0 && distanta[i] < distanta_min)
        {
            distanta_min = distanta[i];
            u = i;
        }
    return u;
}
void afisaree(int f,int *tata, ofstream &g)
{
    if(tata[f] == 0)
        g << f << " ";
    else
     {
         afisaree(tata[f], tata, g);
         g << f << " ";
     }

}
void Dijkstra(int s, int n, int matrice_cost[100][100], ofstream &g)
{
    int curent,  *tata, *viz,j,i;
    double *distanta;

    distanta=new double[n+1];
    tata=new int[n+1];
    viz=new int[n+1];

    for(i=1; i<=n; i++)
    {
        viz[i] = tata[i] = 0;
        distanta[i] = infinit;
    }
    distanta[s] = 0;
    for(i=1; i<=n-1; i++)
    {

        curent = minim(distanta,viz,n);//varful nevizitat cu d minim
        viz[curent] = 1;
        g << "Extras: " << curent << endl;
        //actualizam etichetele vecinilor nevizitati
        for(j=1; j<=n; j++)
            if(matrice_cost[curent][j] < infinit && viz[j]==0)
                if(distanta[j] > matrice_cost[curent][j]+distanta[curent])
                {
                    distanta[j] = distanta[curent]+matrice_cost[curent][j];
                    tata[j] = curent;
                }
    }
    g << endl;
    int h;
    cout << "Nod final: ";
    cin >> h;
    afisaree(h, tata,g);
}

int main()
{

    ifstream f("graf.in");
    ofstream g("graf.out");
    int m,n, matrice_cost[100][100], x, y, c, i, j, s, mc;

    f>>n;
    f>>m;
    //initializam cu infinit si diagonala cu 0
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            matrice_cost[i][j]=infinit;
    for(i=1; i<=n; i++)
        matrice_cost[i][i]=0;

    //citim muchiile
    for(i=1; i<=m; i++)
    {
        f>>x>>y>>c;
        matrice_cost[x][y]=c;
        //neorientat
       // matrice_cost[y][x]=c;
    }
    f.close();
    cout<<"Introduceti varful de start: ";
    cin>>s;
    Dijkstra(s,n,matrice_cost,g);
    g.close();

    return 0;

}

