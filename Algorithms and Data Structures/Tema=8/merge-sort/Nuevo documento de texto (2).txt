#include <iostream>

using namespace std;

int a[50];

void merge(int,int,int);

void merge_sort(int cel_mai_mic,int cel_mai_mare)
{
    int element_mijloc;
    if(cel_mai_mic<cel_mai_mare)
    {
        element_mijloc = cel_mai_mic + (cel_mai_mare-cel_mai_mic)/2;
        merge_sort(cel_mai_mic,element_mijloc);
        merge_sort(element_mijloc+1,cel_mai_mare);
        merge(cel_mai_mic,element_mijloc,cel_mai_mare);
    }
}

void merge(int cel_mai_mic,int element_mijloc,int cel_mai_mare)
{
    int h,i,j,b[50],k;
    h=cel_mai_mic;
    i=cel_mai_mic;
    j=element_mijloc+1;
    while((h<=element_mijloc)&&(j<=cel_mai_mare))
    {
        if(a[h]<=a[j])
        {
            b[i]=a[h];
            h++;
        }
        else
        {
            b[i]=a[j];
            j++;
        }
        i++;
    }
    if(h>element_mijloc)
    {
        for(k=j; k<=cel_mai_mare; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    else
    {
        for(k=h; k<=element_mijloc; k++)
        {
            b[i]=a[k];
            i++;
        }
    }
    for(k=cel_mai_mic; k<=cel_mai_mare; k++)
        a[k]=b[k];
}
int main()
{
    int numar,i;
    cout<<endl<<"Dati numarul de elemenete: ";
    cin>>numar;
    cout<<endl;
    for(i=1; i<=numar; i++)
        {
            cout<<"Se da elementul: ";
            cin>>a[i];
        }
    merge_sort(1,numar);
    cout<<endl<<"Elementele ordonate prin metoda Merge-Sort: ";
    for(i=1; i<=numar; i++)
        cout<<a[i]<<"  ";
    cout<<endl;
    return 0;
}
