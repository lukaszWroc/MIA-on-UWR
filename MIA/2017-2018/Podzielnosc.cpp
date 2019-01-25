#include<iostream>
#include<queue>

using namespace std;

struct Zmienne
{
    int m,cyfra,ojciec;
    Zmienne(int a,int b,int c):
        m(a),cyfra(b),ojciec(c){};
    Zmienne(){};
};


Zmienne reszta[1000100];
bool vis[1000100];
queue<Zmienne> q;
int n;


void bfs(Zmienne &t,const int &n)
{
    reszta[1] = t;
    q.push(t);
    while(!q.empty())
    {
        t=q.front();
        q.pop();
        if(t.m==0)
            break;
        int r0=(t.m*10)%n;
        int r1=(t.m*10 + 1)%n;
        if(reszta[r0].ojciec == -1){
            reszta[r0] = Zmienne(r0,0,t.m);
            q.push(reszta[r0]);
        }
        if(reszta[r1].ojciec ==-1){
            reszta[r1]= Zmienne(r1,1,t.m);
            q.push(reszta[r1]);
        }
    }
}
void getAnswer()
{

    vector<int>v;
    Zmienne t;
    while(true)
    {
        v.push_back(t.cyfra);
        vis[t.m]=true;
        t = reszta[t.ojciec];


        if(vis[t.m])
            break;
    }
    for(int i=v.size()-1;i>=0;i--)
        cout << v[i];
}

int main()
{
    int n;
    cin >> n;
    for(int i=0;i<=n;i++)
    {
        reszta[i] = Zmienne(-1,-1,-1);
    }
    Zmienne t(1,1,0);
    bfs(t,n);
    getAnswer();
    return 0;
}
