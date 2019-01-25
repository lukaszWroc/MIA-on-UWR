#include<iostream>
#include<queue>
const int N = 404;

using namespace std;

bool tab1[N][N];
bool tab2[N][N];
bool vis[N];
int n;
void clearVis()
{
    for(int i=1;i<=n;i++)
            vis[i] = false;
}
int bfs(bool tab[][N])
{
    int sum = 1;
    bool check = true;
    queue<int>q;
    q.push(1);
    q.push(-1);
    int v;
    clearVis();
    while(!q.empty())
    {
        v = q.front();
        q.pop();
        if(v == -1)
        {
            sum++;
            if(!q.empty())
                q.push(-1);
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            if(vis[i] == false && tab[v][i] == true)
            {
                if(i == n)
                {
                    check = false;
                    break;
                }
                q.push(i);
                vis[i] = true;
            }
        }
        if(!check)
            break;
    }
    if(check)
        return -1;
    return sum;
}
int main()
{
    int m;
    cin >> n >> m;
    int a,b;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        tab1[a][b] = true;
        tab1[b][a] = true;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(!tab1[i][j])
                tab2[i][j] = true;
    int odp1 = bfs(tab1);
    int odp2 = bfs(tab2);
    if(odp1 == -1 || odp2 == -1)
        cout << "-1";
    else
        cout << max(odp1,odp2);
    return 0;
}


/*

4 6
1 2
1 3
1 4
2 3
2 4
3 4

4 2
1 3
3 4

5 5
4 2
3 5
4 5
5 1
1 2


*/
