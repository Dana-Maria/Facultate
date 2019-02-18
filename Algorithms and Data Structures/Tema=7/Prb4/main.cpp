#include <iostream>

using namespace std;

struct nod
{
    int informatie;
    nod* legatura_stanga;
    nod* legatura_dreapta;
};

nod *v;
int n,x;

void inserare( nod *&r, int x )
{
    if(r)
        if( r -> informatie == x )
        {
            cout<<"Numarul deja se afla in arbore; "<<endl;
            n--;
        }
        else if( r -> informatie < x )
            inserare( r -> legatura_dreapta, x );
        else
            inserare( r -> legatura_stanga, x );

    else
    {
        r=new nod;
        r -> informatie= x;
        r -> legatura_stanga= r -> legatura_dreapta= 0;
    }
}


void Afisare_Inordine(nod *r)
{
    if(r)
    {
        Afisare_Inordine(r->legatura_stanga);
        cout<<r->informatie<<" ";
        Afisare_Inordine(r->legatura_dreapta);
    }
}

void La_Dreapta(nod *r, int k1, int k2)
{
    if( k1<=r->informatie && r->informatie<=k2 && r!=NULL )
    {
        cout<<r->informatie<<" ";
        La_Dreapta(r->legatura_dreapta, k1, k2);
        La_Dreapta(r->legatura_stanga, k1, k2);
    }
    return;
}

void La_Stanga(nod *r, int k1, int k2)
{
    if( k1<=r->informatie && r->informatie<=k2 && r!=NULL )
    {
        cout<<r->informatie<<" ";
        La_Dreapta(r->legatura_dreapta, k1, k2);
        La_Dreapta(r->legatura_stanga, k1, k2);
    }
    return;
}

void Decide(nod *r, int k1,int k2)
{
    if(k2<=r->informatie)

            La_Dreapta(r,k1,k2);

    else
        La_Stanga(r,k1,k2);
}

int main()
{
    cout<<"Numarul de noduri: ";
    cin>>n;
    if(n==0)
        return 0;
    cout<<endl;

    for(int i=1; i<=n; i++)
    {
        cout<<"Valoarea de inserat: ";
        cin>>x;
        inserare(v,x);
    }

    cout<<endl<<"Arborele arata astfel (inordine): "<<endl;
    Afisare_Inordine(v);
    cout<<endl;
    int k1,k2;
    do{
        cout<<"k1=";
        cin>>k1;
        cout<<"k2=";
        cin>>k2;
    }while(k1>k2);
    cout<<endl<<"Elementele care respecta regula "<<k1<<" < = x < = "< k2<<", sunt: ";
    Decide(v,k1,k2);
    return 0;
}
