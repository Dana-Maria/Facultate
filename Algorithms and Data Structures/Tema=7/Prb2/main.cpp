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

int search(nod *r,int x)
{
    if(r)
        if( r -> informatie == x )
            return 1;
        else if( r -> informatie < x )
            search( r -> legatura_dreapta, x);
        else
            search( r -> legatura_stanga, x);
    else
        return 0;
}

void cmd( nod* &r, nod* &f )
{
    nod *auxiliar;
    if( f -> legatura_dreapta )
        cmd( r, f -> legatura_dreapta );
    else
        {
            r -> informatie = f -> informatie;
            auxiliar=f;
            f = f -> legatura_stanga;
            delete auxiliar;
        }
}

void Elimina_Element(nod *&r,int x)
{
    nod *auxiliar,*f;
    if(r)
        if( r -> informatie==x )
            if( r -> legatura_stanga == 0 && r -> legatura_dreapta == 0 )
            {
                delete r;
                r=0;
            }
            else
                if(r->legatura_stanga==0)
                    {
                        auxiliar= r-> legatura_dreapta;
                        delete r;
                        r=auxiliar;
                    }
                else
                        if(r->legatura_dreapta==0)
                            {
                                auxiliar=r->legatura_stanga;
                                delete r;
                                r=auxiliar;
                            }
                        else
                            cmd(r,r->legatura_stanga);
        else
            if(r->informatie<x)
                Elimina_Element(r->legatura_dreapta,x);
            else
                Elimina_Element(r->legatura_stanga,x);
    else
        cout<<"Valoarea nu se gaseste in arbore; ";
}

void findMax(nod *r)
{
	if (!r->legatura_dreapta)
		{
		    cout<< r->informatie;
		    return;
		}
    findMax(r->legatura_dreapta);
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

    cout<<endl<<"\nValoarea ce se v-a cauta in arbore este: ";
    cin>>x;
    if( search( v, x ) )
        cout<<"Valoarea se regaseste in arbore;";
    else
        cout<<"Valoarea nu se regaseste in arbore;";

    cout<<endl<<"\nValoarea ce se v-a sterge din arbore: ";
    cin>>x;
    Elimina_Element(v,x);
    cout<<endl<<"Arborele arata astfel (inordine): "<<endl;
    Afisare_Inordine(v);

    cout<<endl<<"\nMaximul din arbore este: ";
    findMax(v);
    cout<<endl;

    return 0;
}
