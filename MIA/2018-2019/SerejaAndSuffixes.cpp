#include<iostream>

const int N = 1000010;

using namespace std;

int tab[N];
int t[N];
bool vis[N];
int main()
{
    int n,m,a;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> tab[i];
    int sum = 0;
    for(int i=n-1;i>=0;i--)
    {
        int a = tab[i];
        if(!vis[a])
        {
            vis[a] = true;
            sum++;
        }
        t[i]=sum;
    }
    for(int i=0;i<m;i++)
    {
        cin >> a;
        cout << t[a-1]<< "\n";
    }

    return 0;
}

