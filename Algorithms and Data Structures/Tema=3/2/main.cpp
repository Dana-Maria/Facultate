#include <iostream>

using namespace std;
struct pol
{
    int gr, coef;
    pol *next;
};

pol *primP, *ultimP, *primQ, *ultimQ;

void primul_element(nod *&prim, nod *&ultim)
{
    prim=new nod;
    cout<<"Valoarea noua adaugata in polinom este: ";
    cin>>prim->info;
    prim->next=NULL;
    ultim=prim;                                                                                                                                                                //            si ultimul
}
void adaugare(nod *&prim, nod *&ultim)
{
    nod *c;
    c=new nod;
    cout<<"Valoarea noua adaugata in polinom este: ";
    cin>>c->info;
    ultim->next=c;
    ultim=c;
    ultim->next=NULL;

}
int main()
{
    int a;
    primP=NULL;
    ultimP=NULL;
    primQ=NULL;
    ultimQ=NULL;
    cout<<"a=";
    cin>>a;
    return 0;
}
