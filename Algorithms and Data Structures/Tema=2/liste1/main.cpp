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
    cout<<"Introduceti valoarea retinuta in primul nod: ";
    cin>>prim->info;
    prim->next=NULL;
    ultim=prim;                                                                                                                                                                //            si ultimul
}

void adaugare()
{
    //a
    nod *c;
    c=new nod;
    cout<<"Valoarea noua adaugata in lista este: ";
    cin>>c->info;
    ultim->next=c;
    ultim=c;
    ultim->next=NULL;
}

void inserare_inceput()
{
    //b
    nod *c;
    c=new nod;
    cin>>c->info;
    c->next=prim;
    prim=c;

}
void afisare()
{
    nod *c;
    c=prim;
    while(c!=0)
    {
        cout<<c->info<<"  ";
        c=c->next;
    }
}

void inserare_dupa(int val)
{
    nod *c,*a;
    c=prim;
    while(c->info!=val &&c)
        c=c->next;
    a=new nod;
    cout<<"Noua valoare: ";
    cin>>a->info;
    a->next=c->next;
    c->next=a;
    if(c==ultim)
        ultim=a;

}
void cautare_valoare(int val)
{
    nod *it =prim;

    while (it!=NULL && it->info!=val)
        it=it->next;
    if(it == NULL)
        cout<<"Nu";
    else
        cout<<"Da";
}
void cautare_pozitie(int pozitie)
{
    nod *e = prim;
    int i = 1;
    while (i < pozitie)
    {
        i++;
        if (e->next == NULL)
        {
            cout << "Nu. Lista nu are destule elemente\n";
            return;
        }
        e = e->next;
    }
    cout <<"Da: "<< e -> info;
}
void sterge_valoare(int val)
{
    nod *c,*a;
    c=prim;
    if(prim->info==val)
    {
        a=prim;
        prim=prim->next;
        delete a;
    }
    else
    {
        while(c->next->info!=val &&c)
            c=c->next;
        a=c->next;
        c->next=a->next;
        if(a==ultim)
            ultim=c;
        delete a;
    }
}
void sterge_pozitie(int pozitie)
{
    nod *del, *ant;
    del=ant=prim;
    for(int i=1; i<pozitie; i++)
    {
        if(i!=1) ant=ant->next;
        del=del->next;
    }
    if(del == ant)
    {
        del = del->next;
        delete ant;
        prim = del;
        return ;
    }
    ant->next=del->next;
    delete del;
}

void sterge_lista()
{
    nod *m, *s;
    m=s=prim;
    for( s=s->next; s->next!=NULL ; s=s->next)
    {
        delete m;
        m=s;

    }
    delete s;
    prim->next=NULL;
    cout<<endl<<"Lista este nula";
}

int main()
{
    int nou;
    primul_element();
    cout<<"(a)";
    adaugare();
    cout<<"Lista arata astfel: ";
    afisare();
    cout<<endl<<"(b)Adaugarea unei nou element pe prima pozitie: ";
    inserare_inceput();
    cout<<"Lista arata astfel: ";
    afisare();
    cout<<endl<<"(c)Adaugarea unui nou element dupa valoarea: ";
    cin>>nou;
    inserare_dupa(nou);
    cout<<"Lista arata astfel: ";
    afisare();
    cout<<endl<<"(d)Afisarea listei: ";
    afisare();
    cout<<endl<<"(e)Valoarea cautata in lista: ";
    cin>>nou;
    cautare_valoare(nou);
    cout<<endl<<"(f)Cautarea unei valori pe pozitia: ";
    cin>>nou;
    cout<<"Se regaseste vreun element pe respectiva pozitie? ";
    cautare_pozitie(nou);
    cout<<endl<<"(g)Valoarea ce urmeaza sa fie stearsa: ";
    cin>>nou;
    sterge_valoare(nou);
    cout<<"Lista arata astfel: ";
    afisare();
    cout<<endl<<"(h)Valoarea ce urmeaza sa fie stearsa de pe pozitia: ";
    cin>>nou;
    sterge_pozitie(nou);
    cout<<"Lista arata astfel: ";
    afisare();
    cout<<endl<<"(i)Stergerea completa a listei";
    sterge_lista();
    return 0;
}
