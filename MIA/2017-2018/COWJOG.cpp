#include<iostream>
#include<vector>
const long long int INF = -2000000000000000000;
using namespace std;

vector<long long int>t;
long long int tab[100010];

int wyszukaj(long long int x,int p)
{
    int l=0,s,d=0;
    while(l<=p){
        s=(l+p)/2;
        if(tab[s]<=x)
        {
            d=s;
            l=s+1;
        }
        else
            p=s-1;

    }
    return d+1;
}
int main()
{
    cin.sync_with_stdio(false);
    long long int a,b,T;
    int n,maxx=0,x;
    cin >> n >> T;
    for(int i=0;i<n;i++)
    {
        cin>> a >> b;
        t.push_back(-a-b*T);
    }
    tab[0]=INF;
    for(int i=0;i<n;i++)
    {
        x=wyszukaj(t[i],maxx);
        tab[x]=t[i];
        maxx=max(maxx,x);
    }
    cout << maxx;
    return 0;
}
