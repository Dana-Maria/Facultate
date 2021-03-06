#include <iostream>
#include<conio.h>

using namespace std;
/*   5. Sa se implementeze o coada de numere intregi, cu urmatoarele operatii:
(a) void push(a, coada) care adauga elementul a in coada;
(b) int pop(coada) care scoate primul element din coada, si il intoarce ca
rezultat al functiei;
(c) int peek(coada) care �ntoarce primul element din coada, fara a-l
scoate;
(d) bool empty(coada) care verifica daca coada este vida sau nu;
(e) int search(a, coada) care intoarce -1 daca elementul a nu se afla
in coada. Daca a apare in stiva, atunci functia intoarce distanta de la primul
element al cozii pana la aparitia cea mai apropiata de primul element al cozii.
Se va considera ca primul element se afla la distanta 0.
(f) void afiseaza(coada) care afiseaza coada, pornind de la primul
element si continu�nd spre ultimul.

*/
struct nod
{
    int info;
    nod *next;
};

struct coada {
    nod* varf;
    nod* ultimul;
};


void push(nod* &a, nod* &sf, int x)
{
    nod *c;
    if(!a)
    {
        a=new nod;
        a->info=x;
        a->next=0;
        sf=a;
    }
    else
    {
        c=new nod;
        sf->next=c;
        c->info=x;
        sf=c;
        sf->next=0;
    }
}
bool empty(nod* &a)
{
    if(!a)
        return 0;
    else
        return 1;
}
void afisare(nod *a)
{
    nod *c;
    c=a;
    while(c)
    {
        cout<<c->info;
        cout<<" ";
        c=c->next;
    }
}
int peek(nod* &a)
{
    nod* c;
    int x;
    c=a;
    x=a->info;
    return x;
}
int pop(nod* &a)
{
    nod* c;
    int x;
    c=a;
    x=a->info;
    a=a->next;
    delete c;
    return x;
}
int search(nod* &a, int x)
{
    nod *c;
    int i=0;
    c=a;
    while(c)
    {
        if(c->info==x)
            return i;
        c=c->next;
        i++;
    }
    return -1;
}

int main()
{
    int n,a,i,x;
    nod *varf=0,*ultim=0;
    cout<<"Numarul initial de noduri: ";
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cout<<"(a)Valoarea ce urmeaza sa fie adaugata in coada: ";
        cin>>a;
        push(varf, ultim, a);
    }
    if(empty(varf)==0)
    {
        cout<<"Coada este nula";
        return 0;
    }
    cout<<"Coada arata astfel: ";
    afisare(varf);
    cout<<endl<<"(b)Se va elimina primul element din coada "<<pop(varf);
    cout<<endl<<"Coada arata astfel: ";
    n--;
    afisare(varf);
    cout<<endl<<"(c)Se va afisa primul element din coada: "<<peek(varf)<<endl;
    if(empty(varf)==0)
    {
        cout<<"(d)Coada este nula";
        return 0;
    }
    else
    {
        cout<<"(d)Coada nu este nula: ";
        afisare(varf);
    }
    cout<<endl<<"(e)Se va cauta in coada valoarea: ";
    cin>>x;
    int pozitie = search(varf, x);
    if(pozitie == -1)
        cout<<"Valoarea nu se regaseste in coada";
    else
        cout<<"Valoarea se regaseste in coada la o distanta: "<<pozitie;
    return 0;

}
