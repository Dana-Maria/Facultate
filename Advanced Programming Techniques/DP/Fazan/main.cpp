#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

string cuvinte[20];
int dp[20];

void recursiv(int x, int i, int j, int n)
{
    if( j == n)
    {
        return;
    }
    if(cuvinte[j].substr(0, 2) == cuvinte[i].substr(cuvinte[i].size() - 2, 2))
    {
        dp[x]++;
        recursiv(x, j, j + 1, n);
    }
    else
        recursiv(x, i, j + 1, n);
}

void recursiva(int i, int j, int n)
{
    if( i == n || j == n)
    {
        cout << cuvinte[i] << " ";
        return;
    }
    if(cuvinte[j].substr(0, 2) == cuvinte[i].substr(cuvinte[i].size() - 2, 2))
    {
        cout << cuvinte[i] << " ";
        recursiva(j, j + 1, n);
    }
    else
        recursiva(i, j + 1, n);
}
int main()
{

    int i = 0;
    ifstream f("fis.in");
    while(f)
    {
        f >> cuvinte[i];
        i++;
    }

    int n = i - 1;

    for( i = 0 ; i < n ; i++)
        dp[i] = 1;
    for( i = 0 ; i < n ; i++)
    {
        recursiv(i, i, i+1, n);
    }
    int maxx = 1, pozMax = -1;
    for( i = 0 ; i < n ; i++)
        if(maxx < dp[i])
        {
            maxx = dp[i];
            pozMax = i;
        }

    recursiva(pozMax, pozMax + 1, n);
    return 0;
}
