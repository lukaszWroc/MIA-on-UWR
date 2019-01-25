#include<iostream>

const int N = 100100;

using namespace std;

int tab[N];

int main()
{
    int n,a,maxx=0;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        tab[a]++;
        maxx = max(maxx,a);
    }
    bool check = true;
    for(int i=0;i<=maxx;i++)
    {
        if(tab[i]%2 == 1)
        {
            check = false;
            break;
        }
    }
    if(check)
        cout << "Agasa";
    else
        cout << "Conan";
    return 0;
}

