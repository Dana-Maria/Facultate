#include <iostream>

using namespace std;

struct Element
{
	Element *urm;
	int info;
};

struct Lista
{
	Element* primul = NULL;
	Element* ultimul = NULL;
	~Lista()
	{
		if (!primul)
			return;
		if (primul == ultimul)
            {
                delete primul;
                primul = ultimul = NULL;
                return;
            }
		Element* precedent = primul;
		for (Element* element = primul->urm; element; element = element->urm)
            {
                delete precedent;
                precedent = element;
            }
		if (ultimul)
			delete ultimul;
		primul = ultimul = NULL;
	}

void Adauga(int element)
{
		Element* elementNou = new Element;
		elementNou->info = element;
		elementNou->urm = NULL;
		if (!primul && !ultimul)
            {
                primul = elementNou;
                ultimul = elementNou;
            }
		else
            {
                ultimul->urm = elementNou;
                ultimul = elementNou;
            }
}

void Afiseaza()
{
		for (Element* element = primul; element; element = element->urm)
			cout<<element->info<<" ";
		cout<<endl;
	}
};

int main()
{
	Lista a, b;
	int n,k;
	int v[100];
	cout<<"Cate elemente va avea lista A?\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
	    cout<<"Element ce urmeaza sa fie adaugat in lista A: ";
	    cin>>k;
        a.Adauga(k);
        v[i]=k;
	}
	cout<<"Lista A arata astfel: ";
	a.Afiseaza();
	n--;
    for(int i=n;i>=0;i--)
    {
        k=v[i];
        b.Adauga(k);
    }
    cout<<"Lista B arata astfel: ";
    b.Afiseaza();
	return 0;
}
