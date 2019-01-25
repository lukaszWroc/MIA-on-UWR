#include<iostream>

const int N = 1010;
using namespace std;

bool tab[N];
int main()
{
    int n,m;
    cin >> n >> m;
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        tab[a] = true;
        tab[b] = true;
    }
    int v;
    for(int i=1;i<=n;i++)
    {
        if(!tab[i])
        {
            v = i;
            break;
        }
    }
    cout << n-1 << "\n";
    for(int i=1;i<=n;i++)
    {
        if(i!=v)
            cout << v << " " << i << "\n";
    }

}
