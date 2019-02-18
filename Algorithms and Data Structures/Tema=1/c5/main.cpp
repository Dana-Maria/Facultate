#include <iostream>

using namespace std;
//Cautare binara
int main()
{
    int x,n,st,dr,m,i,v[10];
    cout<<"n=";
    cin>>n;
    cout<<"x=";
    cin>>x;
    cout<<"Sirul va fi dat in ordine crescatoare!"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<"v["<<i<<"]=";
        cin>>v[i];
    }
    st=0;
    dr=n+1;
    m=(st+dr)/2;
    while(dr-st>1)
    {
        if(v[m]==x)
        {
            cout<<x<<" se regaseste in sir";
            return 0;
        }
        if(v[m]<=x)
            st=m;
        else
            dr=m-1;
        m=(st+dr)/2;
    }
    cout<<x<<" nu se regaseste in sir";
    return 0;
}
