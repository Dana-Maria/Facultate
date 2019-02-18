#include <iostream>
#include<cctype>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct node
{
    int element;
    node *element_la_stanga;
    node *element_la_dreapta;
    int inaltime;
};
typedef struct node *nodeptr;
void insert(int,nodeptr &);
void del(int, nodeptr &);
int deletemin(nodeptr &);
void gaseste(int,nodeptr &);
void makeempty(nodeptr &);
void copy(nodeptr &,nodeptr &);
nodeptr nodecopy(nodeptr &);
void inordine(nodeptr);
int bsinaltime(nodeptr);
nodeptr srl(nodeptr &);
nodeptr drl(nodeptr &);
nodeptr srr(nodeptr &);
nodeptr drr(nodeptr &);
int max(int,int);
int faranoduri(nodeptr);
void   insert(int x,nodeptr &p)
{
    if (p == NULL)
    {
        p = new node;
        p->element = x;
        p->element_la_stanga=NULL;
        p->element_la_dreapta = NULL;
        p->inaltime=0;
        if (p==NULL)
            cout<<"Fara spatiu\n"<<endl;
    }
    else
    {
        if (x<p->element)
        {
            insert(x,p->element_la_stanga);
            if ((bsinaltime(p->element_la_stanga) - bsinaltime(p->element_la_dreapta))==2)
            {
                if (x < p->element_la_stanga->element)
                    p=srl(p);
                else
                    p = drl(p);
            }
        }
        else if (x>p->element)
        {
            insert(x,p->element_la_dreapta);
            if ((bsinaltime(p->element_la_dreapta) - bsinaltime(p->element_la_stanga))==2)
            {
                if (x > p->element_la_dreapta->element)
                    p=srr(p);
                else
                    p = drr(p);
            }
        }
        else
            cout<<"Elementul exista deja\n"<<endl;
    }
    int m,n,d;
    m=bsinaltime(p->element_la_stanga);
    n=bsinaltime(p->element_la_dreapta);
    d=max(m,n);
    p->inaltime = d + 1;
}
nodeptr gasestemin(nodeptr p)
{
    if (p==NULL)
    {
        cout<<"Arborele este gol\n"<<endl;
        return p;
    }
    else
    {
        while(p->element_la_stanga !=NULL)
            p=p->element_la_stanga;
        return p;
    }
}

nodeptr  gasestemax(nodeptr p)
{
    if (p==NULL)
    {
        cout<<"Arborele este gol\n"<<endl;
        return p;
    }
    else
    {
        while(p->element_la_dreapta !=NULL)
            p=p->element_la_dreapta;
        return p;
    }
}

void  gaseste(int x,nodeptr &p)
{
    if (p==NULL)
        cout<<"Elementul "<<x<<" nu a fost gasit\n"<<endl;
    else
    {
        if (x < p->element)
            gaseste(x,p->element_la_stanga);
        else
        {
            if (x>p->element)
            {
                gaseste(x,p->element_la_dreapta);
            }
            else
            {
                cout<<"Elementul "<<x<<" a fost gasit!\n"<<endl;
            }
        }
    }
}

void  copy(nodeptr &p,nodeptr &p1)
{
    makeempty(p1);
    p1 = nodecopy(p);
}

void makeempty(nodeptr &p)
{
    nodeptr d;
    if (p != NULL)
    {
        makeempty(p->element_la_stanga);
        makeempty(p->element_la_dreapta);
        d=p;
        free(d);
        p=NULL;
    }
}

nodeptr nodecopy(nodeptr &p)
{
    nodeptr temp;
    if (p==NULL)
        return p;
    else
    {
        temp = new node;
        temp->element = p->element;
        temp->element_la_stanga = nodecopy(p->element_la_stanga);
        temp->element_la_dreapta = nodecopy(p->element_la_dreapta);
        return temp;
    }
}

void  del(int x,nodeptr &p)
{
    nodeptr d;
    if (p==NULL)
        cout<<"Elementul nu a fost gasit\n"<<endl;
    else if ( x < p->element)
        del(x,p->element_la_stanga);
    else if (x > p->element)
        del(x,p->element_la_dreapta);
    else if ((p->element_la_stanga== NULL) && (p->element_la_dreapta == NULL))
    {
        d=p;
        free(d);
        p=NULL;
        cout<<"Elementul a fost sters\n"<<endl;
    }
    else if (p->element_la_stanga == NULL)
    {
        d=p;
        free(d);
        p=p->element_la_dreapta;
        cout<<"Elementul a fost sters\n"<<endl;
    }
    else if (p->element_la_dreapta == NULL)
    {
        d=p;
        p=p->element_la_stanga;
        free(d);
        cout<<"Elementul a fost sters\n"<<endl;
    }
    else
        p->element = deletemin(p->element_la_dreapta);
}

int   deletemin(nodeptr &p)
{
    int c;
    if (p->element_la_stanga == NULL)
    {
        c=p->element;
        p=p->element_la_dreapta;
        return c;
    }
    else
    {
        c=deletemin(p->element_la_stanga);
        return c;
    }
}

void preordine(nodeptr p)
{
    if (p!=NULL)
    {
        cout<<p->element<<" ";
        preordine(p->element_la_stanga);
        preordine(p->element_la_dreapta);
    }
}

void  inordine(nodeptr p)
{
    if (p!=NULL)
    {
        inordine(p->element_la_stanga);
        cout<<p->element<<" ";
        inordine(p->element_la_dreapta);
    }
}

void postordine(nodeptr p)
{
    if (p!=NULL)
    {
        postordine(p->element_la_stanga);
        postordine(p->element_la_dreapta);
        cout<<p->element<<" ";
    }
}

int max(int val1, int val2)
{
    return ((val1 > val2) ? val1 : val2);
}
int bsinaltime(nodeptr p)
{
    int t;
    if (p == NULL)
        return -1;
    else
    {
        t = p->inaltime;
        return t;
    }
}

nodeptr  srl(nodeptr &p1)
{
    nodeptr p2;
    p2 = p1->element_la_stanga;
    p1->element_la_stanga = p2->element_la_dreapta;
    p2->element_la_dreapta = p1;
    p1->inaltime = max(bsinaltime(p1->element_la_stanga),bsinaltime(p1->element_la_dreapta)) + 1;
    p2->inaltime = max(bsinaltime(p2->element_la_stanga),p1->inaltime) + 1;
    return p2;
}
nodeptr srr(nodeptr &p1)
{
    nodeptr p2;
    p2 = p1->element_la_dreapta;
    p1->element_la_dreapta = p2->element_la_stanga;
    p2->element_la_stanga = p1;
    p1->inaltime = max(bsinaltime(p1->element_la_stanga),bsinaltime(p1->element_la_dreapta)) + 1;
    p2->inaltime= max(p1->inaltime,bsinaltime(p2->element_la_dreapta)) + 1;
    return p2;
}
nodeptr  drl(nodeptr &p1)
{
    p1->element_la_stanga=srr(p1->element_la_stanga);
    return srl(p1);
}
nodeptr drr(nodeptr &p1)
{
    p1->element_la_dreapta = srl(p1->element_la_dreapta);
    return srr(p1);
}

int faranoduri(nodeptr p)
{
    int numara=0;
    if (p!=NULL)
    {
        faranoduri(p->element_la_stanga);
        faranoduri(p->element_la_dreapta);
        numara++;
    }
    return numara;
}

int main()
{
    nodeptr root,max;
    int n;
    int a,gasesteele,stergeele;
    root = NULL;
    cout<<"Numarul de noduri de introdus in arbore: ";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"Pune o valoare: ";
        cin>>a;
        insert(a,root);
    }
    if (root !=NULL)
    {
        max=gasestemax(root);
        cout<<"\nElementul maxim din arbore este: "<<max->element<<endl;
    }
    cout<<"\nNodul cautat: ";
    cin>>gasesteele;
    if (root != NULL)
        gaseste(gasesteele,root);
    cout<<"\nNodul pe care il sterg este: ";
    cin>>stergeele;
    del(stergeele,root);
    cout<<"\nPREORDINE(RSD)"<<endl;
    preordine(root);
    cout<<endl;
    cout<<"\nINORDINE(SRD)"<<endl;
    inordine(root);
    cout<<endl;
    cout<<"\nPOSTORDINE(SDR)"<<endl;
    postordine(root);
    cout<<endl;
    return 0;
}
