#include <iostream>

using namespace std;
/* (3 p) 3. Fie lista simplu inlantuita C. Sa se distribuie elementele din C in doua liste
simplu inlatuite A si B, astfel: A contine elementele de pe pozitiile impare din C, iar B
contine elementele din C de pe pozitiile pare. Nu se va folosi memorie
suplimentara.
*/
struct Element
{
	Element *urm;
	int info;
};

struct Lista
{
	Element* primul = NULL;
	Element* ultimul = NULL;
	Lista()
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
	Lista a, b, c;
	int n,i,k;
	cout<<"Cate elemente va avea lista C?\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
	    cout<<"Element ce urmeaza sa fie adaugat in lista C: ";
	    cin>>k;
        c.Adauga(k);
	}
	cout<<"Lista C arata astfel: ";
	c.Afiseaza();
	Element *elementC = c.primul;
	i=1;
	while (elementC)
    {
		if (i%2!=0)
		{
			a.Adauga(elementC->info);
			elementC = elementC->urm;
		}
		else
		{
			b.Adauga(elementC->info);
			elementC = elementC->urm;
		}
        i++;
	}
    cout<<"Lista A arata astfel: ";
	a.Afiseaza();
	cout<<"Lista B arata astfel: ";
	b.Afiseaza();
	return 0;
}
