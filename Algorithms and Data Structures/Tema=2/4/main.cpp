#include <iostream>

using namespace std;
/* Numărul întreg 82564 este reprezentat ca lista punînd fiecare cifră în câte un nod.
  4 -> 6 -> 5 -> 2 -> 8 */

int n,m;
struct nod
    {
        int info;
        nod *next;
    };

nod *prim1, *ultim1, *prim2, *ultim2, *prim3, *ultim3;

void prima_cifra(nod *&prim, nod *&ultim)
    {
        prim=new nod;
        cout<<"Prima cifra din numar: ";
        cin>>prim->info;
        prim1->next=NULL;
        ultim=prim;                                                                                                                                                                //            si ultimul
    }

void adaugare_cifra(nod *&prim, nod *&ultim)
    {
        nod *c;
        c=new nod;
        cout<<"Urmatoarea cifra din numar: ";
        cin>>c->info;
        ultim->next=c;
        ultim=c;
        ultim->next=NULL;
    }

void aduna_numere()
    {
        nod *c;
        c=new nod;
        int max;
        if(n<m)
            max=m;
        else
            max=n;
        for(int i=0; i<max ; i++)
        {
            prim3->info=prim1->info+prim2->info;
            prim3->next=NULL;
            ultim3=prim3;
        }

    }

void afisare(nod *&prim)
    {
        nod *c;
        c=prim;
        while(c!=0)
        {
            cout<<c->info;
            c=c->next;
        }
    }

int main()
    {
        prim1=NULL;
        ultim1=NULL;
        prim2=NULL;
        ultim2=NULL;
        prim3=NULL;
        ultim3=NULL;
        cout<<"Primul numar este de lungimea n=";
        cin>>n;
        cout<<"Al doilea numar este de lungimea m=";
        cin>>m;
        prima_cifra(prim1, ultim1);
        for(int i=0;i<n-1;i++)
            adaugare_cifra(prim1, ultim1);
        cout<<endl<<"Primul numar: ";
        afisare(prim1);
        cout<<endl<<endl;
        prima_cifra(prim2, ultim2);
        for(int i=0;i<m-1;i++)
            adaugare_cifra(prim2, ultim2);
        cout<<endl<<"Al doilea numar ";
        afisare(prim2);
        cout<<endl<<endl;
        aduna_numere();
        afisare(prim3);
        return 0;
    }
