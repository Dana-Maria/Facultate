#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
/*
Se dă un cuvânt formate numai cu litere.
a) Să se determine câte palindromuri (subsecvenţe egale cu inversele lor) conţine cuvântul O(n2)
*/
string cuvant;
int dp[100][100];
int suma;
void dppp(int i)
{
    int j;
    int k = 2;
    dp[i][i] = 1;
    suma++;
    int n = cuvant.size();
    for(j = i+1 ; j < n ; j++ )
    {
        string s = cuvant.substr(i, k);
        string ss = s;
        reverse(ss.begin(), ss.end());
        if( ss == s)
            {
                dp[i][j] = 1;
                suma++;
            }
        k++;
    }
}
int main()
{
    int i, j, maxim = 0;

    ifstream f("fis.in");
    f >> cuvant;

    int n = cuvant.size();
    j = 0;
    for(i = 0 ; i < n ; i++)
    {
        dppp(i);
    }
    cout << "Numarul de palindroame: " << suma << endl;
    return 0;
}
