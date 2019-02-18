#include <iostream>

using namespace std;
/*
3. Să se creeze o listă simplu înlănţuită alocată dinamic în care se vor reţine
numere întregi. Să se scrie o funcţie care să modifice lista, adăugând între fiecare 2
elemente consecutive în listă media lor aritmetică.
*/
struct nod
        {
            float info;
            nod *next;
        };

nod *start, *p, *r;

void creare()
{
    int i,inf,n;
    cout<<"n=";
    cin>>n;
    cout<<"Primul element din lista: ";
    cin>>inf;
    start=new nod;
    start->info=inf;
    start->next=NULL;
    p=start;
    for(i=2; i<=n; i++)
        {
            cout<<"Se adauga un nou element in lista: ";
            cin>>inf;
            r=new nod;
            r->info=inf;
            r->next=start;
            start=r;
        }
}

void afisare()
{
    p=start;
    while (p!= NULL)
        {
            cout<<p->info<<" ";
            p = p->next;
        }
}

int main()
{
    float s;
    creare();
    p=start;
    while (p->next!=NULL)
        {
            s=p->info+p->next->info;
            r=new nod;
            r->info=s/2;
            r->next=p->next;
            p->next=r;
            p=p->next->next;
        }
    cout<<"Lista arata astfel: ";
    afisare();
    return 0;
}
