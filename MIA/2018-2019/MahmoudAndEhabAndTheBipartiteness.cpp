#include<iostream>
#include<vector>
const int N = 1000010;
using namespace std;
vector<int>tab[N];
int color[N];
bool vis[N];
void dfs(int x,int c)
{
    vis[x] = true;
    color[x] = c;
    for(int i=0;i<tab[x].size();i++)
    {
        int v = tab[x][i];
        if(!vis[v])
        {
            dfs(v,-1*c);
        }
    }
}
int main()
{

    int m,n;
    cin >> n;
    m=n-1;
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        tab[a].push_back(b);
        tab[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
            dfs(i,1);
    }
    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        if(color[i] == -1)
            cnt++;
    }
    long long int sum = 0;
    for(int i=1;i<=n;i++)
    {
        if(color[i] == 1)
        {
            sum += (cnt - tab[i].size());
        }
    }
    cout << sum;
    return 0;
}


