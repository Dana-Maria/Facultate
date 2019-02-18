#include <iostream>

using namespace std;
//Sortarea prin selecţie (Selection Sort)
int main()
{
    int k,i,j,n,a[100],min;
    cout<<"n=";
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cout<<"a["<<i<<"]=";
        cin>>a[i];
    }
    cout<<"Sirul original arata de forma:"<<endl;
    for(i=1; i<=n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    for(i=1; i<=n-1; i++)
    {
        k=i;
        min=a[i];
        for(j=i+1; j<=n; j++)
            if(a[j]<min)
            {
                k=j;
                min=a[j];
            }
        a[k]=a[i];
        a[i]=min;
    }
    cout<<"Sirul ordonat crescator arata de forma:"<<endl;
    for(i=1; i<=n; i++)
        cout<<a[i]<<" ";
    return 0;
}
