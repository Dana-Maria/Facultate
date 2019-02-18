#include <iostream>

using namespace std;

struct nod
{
    int informatie;
    nod *legatura_stanga;
    nod *legatura_dreapta;
};

void Crearea_Arborelui(nod *&radacina)
{
    int n;
    cin>>n;
    if(n!=0)
    {
        radacina=new nod;
        radacina->informatie=n;
        cout<<"Informatia la stanga a lui "<<n<<" este: ";
        Crearea_Arborelui(radacina->legatura_stanga);
        cout<<"Informatia la dreapta a lui "<<n<<" este: ";
        Crearea_Arborelui(radacina->legatura_dreapta);
    }
    else
        radacina=NULL;
}

void RSD(nod *radacina)
{
    if(radacina!=NULL)
    {
        cout<<radacina->informatie<<" ";
        RSD(radacina->legatura_stanga);
        RSD(radacina->legatura_dreapta);
    }
}

void SRD(nod *radacina)
{
    if(radacina!=NULL)
    {
        SRD(radacina->legatura_stanga);
        cout<<radacina->informatie<<" ";
        SRD(radacina->legatura_dreapta);
    }
}

void SDR(nod *radacina)
{
    if(radacina!=NULL)
    {
        SDR(radacina->legatura_stanga);
        SDR(radacina->legatura_dreapta);
        cout<<radacina->informatie<<" ";
    }
}

int main()
{
    nod* radacina;
    cout<<"\nRadacina arborelui are informatia: ";
    Crearea_Arborelui(radacina);
    cout<<endl<<"Parcurgea in Preordine(RSD): ";
    RSD(radacina);
    cout<<endl;
    cout<<"\nParcurgea in Inordine(SRD): ";
    SRD(radacina);
    cout<<endl;
    cout<<"\nParcurgea in Postordine(SDR): ";
    SDR(radacina);
    cout<<endl;
    return 0;
}
