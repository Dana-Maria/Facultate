#include <iostream>

using namespace std;
//Cautarea secventiala
int main()
{
    int v[100],n,x,i;
    cout<<"n=";
    cin>>n;
    cout<<"x=";
    cin>>x;
    for(i=0; i<n; i++)
        {
            cout<<"v["<<i<<"]=";
            cin>>v[i];
        }
    for(i=0; i<n; i++)
        if(v[i]==x)
            {
                cout<<"Elementul "<<x<<" a fost gasit in sir";
                return 0;
            }
    cout<<"Elementul "<<x<<" nu a fost gasit in sir";
    return 0;
}
