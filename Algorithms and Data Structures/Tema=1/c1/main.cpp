#include <iostream>

using namespace std;
//Bubble � Sort (sortarea prin interschimbare)
int main()
{
    int a[100],i,j,aux,n;
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
    for(j=2; j<n; j++)
        for(i=n; i>=j; i--)
            if(a[i-1]>a[i])
            {
                aux=a[i-1];
                a[i-1]=a[i];
                a[i]=aux;
                for(i=1; i<=n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
            }
        cout<<endl;
    cout<<"Sirul ordonat arata de forma:"<<endl;
    for(i=1; i<=n; i++)
        cout<<a[i]<<" ";
    return 0;
}
