#include<iostream>

const int N = 600;
const int INF = 1000100;
using namespace std;

long long int dist[N][N];
int q[N];
long long int an[N];
bool vis[N];
int n;

void initialize()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = INF;
        }
    }
}

int main()
{
    cin >> n;
   // initialize();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin >>  dist[i][j];
    for(int i=1;i<=n;i++)
        cin >> q[i];

    for(int a=n;a>0;a--)
    {
        int k = q[a];
        long long int sum = 0;
        vis[k] = true;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(vis[i] && vis[j])
                    sum +=dist[i][j];
            }
        }
        an[a] = sum;
    }
    for(int i=1;i<=n;i++)
        cout << an[i] << " ";
    return 0;
}


/*


4
0 3 1 1
6 0 400 1
2 4 0 1
1 1 1 0
4 1 2 3

2
0 5
4 0
1 2

1
0
1

*/
