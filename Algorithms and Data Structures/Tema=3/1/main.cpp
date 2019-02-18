#include <iostream>

using namespace std;

struct nod
{
    int info;
    nod *next;
};

nod *prim, *ultim;

void primul_element()
{
    prim=new nod;
    cout<<"Noul element ce urmeaza sa fie inserat in lista: ";
    cin>>prim->info;
    prim->next=NULL;
    ultim=prim;                                                                                                                                                                //            si ultimul
}

void adaugare()
{
    nod *c;
    c=new nod;
    cout<<"Noul element ce urmeaza sa fie inserat in lista: ";
    cin>>c -> info;
    if(prim->info < c->info)
        {
            ultim -> next=c;
            ultim=c;
            ultim -> next=NULL;
        }
    else
        {
            c -> next=prim;
            prim=c;
        }

}

void afisare()
{
    nod *c;
    c=prim;
    while(c!=0)
        {
            cout<<c -> info<<"  ";
            c= c-> next;
        }
}
int main()
{
    int n;
    cout<<"n=";
    cin>>n;
    if(n!=0)
        primul_element();
    for(int i=0; i<n-1; i++)
        adaugare();
    if(n!=0)
        {
            cout<<"Lista ordonata arata astfel: ";
            afisare();
        }
    else
        cout<<"Lista nu are elemente";
    return 0;
}
