#include <iostream>
//stive
using namespace std;
/* 1. Să se implementeze cu alocare dinamică o stivă de numere întregi, cu
următoarele operatii:
(a) void push (a, stiva) care adaugă elementul a în vârful stivei;
(b) int pop (stiva) care scoate elementul din vârful stivei şi îl intoarce ca
rezultat al funcţiei;
(c) int peek(stiva) care întoarce elementul din vârful stivei, fără a-l
scoate;
(d) bool empty(stiva) care verifică dacă stiva este vidă sau nu;
(e) int search(a, stiva) care intoarce -1 daca elementul a nu se află in
stiva. Daca a apare in stiva, atunci functia intoarce distanta de la varful stivei
pana la aparitia cea mai apropiata de varf. Se va considera ca varful se afla la
distanta 0.
(f) void afiseaza(stiva) care afiseaza stiva, pornind de la varful ei si
continuand spre baza.*/

struct nod
{
    int info;
    nod *back;
};

nod *varf;

void push(nod* &a,int x)
{
    nod *c;
    if(!a)
    {
        a=new nod;
        a->info=x;
        a->back=0;
    }
    else
    {
        c=new nod;
        c->back=a;
        c->info=x;
        a=c;
    }
}

void afisare(nod *a)
{
    nod *c;
    c=a;
    while(c)
    {
        cout<<c->info<<" ";
        c=c->back;
    }
}

int pop(nod* &a)
{
    nod* c;
    int b;
    c=a;
    b=a->info;
    a=a->back;
    delete c;
    return b;

}

int peek(nod* &a)
{
    nod* c;
    int b;
    c=a;
    b=a->info;
    return b;
}

bool empty(nod* &a)
{
    if(!a)
        return 0;
    else
        return 1;
}

int search(nod* &a,int x)
{
    nod *c;
    int i=0;
    c=a;
    while(c)
    {
        if(c->info==x)
            return i;
        c=c->back;
        i++;
    }
    return -1;
}

int main()
{
    int n,a,x;
    cout<<"Numarul nodurilor din stiva: ";
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cout<<"(a)Valoarea ce urmeaza sa fie adaugata in stiva: ";
        cin>>a;
        push(varf,a);
    }
    if(empty(varf)==0)
    {
        cout<<"Stiva este nula";
        return 0;
    }
    cout<<"Stiva arata astfel: ";
    afisare(varf);
    cout<<endl;
    if(empty(varf)!=0)
    {
        cout<<endl<<"(b)Urmeaza sa fie eliminat varful stivei: "<<pop(varf);
        n--;
        if(empty(varf)!=0)
        {
            cout<<endl<<"Stiva arata astfel: ";
            afisare(varf);
        }
    }
    else
        {
            cout<<"(b)Stiva este nula."<<endl;
            return 0;
        }
    cout<<endl<<"(c)Varful stivei: "<<peek(varf)<<endl;
    if(empty(varf)==0)
        cout<<"(d)Stiva este nula.";
    else
        cout<<"(d)Stiva nu este nula.";
    cout<<endl;
    cout<<"(e)Se va cauta in stiva valoarea: ";
    cin>>x;
    int pozitie = search(varf, x);
    if(pozitie == -1)
        cout<<"Valoarea nu se regaseste in stiva";
    else
        cout<<"Valoarea se regaseste in stiva la o distanta: "<<pozitie;
    return 0;

}

