#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool vis[10000100];
vector<int>tab;
int ojc[10000100];
struct Zmienne{
    int a,b,c;
};
vector<Zmienne>krawedzie;

bool cmp(const Zmienne &x,const Zmienne &y)
{
    return x.c<y.c;
}

int wyszukiwanie(int szukana)
{
    int l=0,p=tab.size()-1,s,odp=0;
    while(l<=p)
    {
        s=(l+p)/2;
        if(tab[s] >= szukana)
        {
            odp=s;
            p=s-1;
        }
        else
           l=s+1;
    }
    return tab[odp];
}
int fin(int x)
{
    if(x==ojc[x])
        return x;
    ojc[x]=fin(ojc[x]);
    return ojc[x];
}
void onion (int x,int y)
{
    ojc[x]=ojc[y];
}

int main()
{
    int n,a,b,najwieksza;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        if(!vis[a])
        {
            tab.push_back(a);
            vis[a]=true;
        }
    }
    sort(tab.begin(),tab.end());

    najwieksza=tab[tab.size()-1];
    for(int i=0;i<tab.size();i++)
    {
        int t,pr=-1;
        Zmienne ts;
        if(tab[i] < najwieksza)
        {
            t=wyszukiwanie(tab[i]+1);
            pr=t;
            ts.a=tab[i];
            ts.b=t;
            ts.c=min(t%tab[i],tab[i]%t);
            krawedzie.push_back(ts);
        }
        int k=2;
        while(k*tab[i] <= najwieksza)
        {
            t=wyszukiwanie(k*tab[i]);
            if(pr != t)
            {
                pr=t;
                ts.a=tab[i];
                ts.b=t;
                ts.c=min(t%tab[i],tab[i]%t);
                krawedzie.push_back(ts);
            }
            k++;
        }
    }
    sort(krawedzie.begin(),krawedzie.end(),cmp);
    for(int i=0;i<tab.size();i++)
    {
        ojc[tab[i]]=tab[i];
    }
    long long int wyn=0LL;
    for(int i=0;i<krawedzie.size();i++)
    {
        a=fin(krawedzie[i].a);
        b=fin(krawedzie[i].b);
        if(a!=b){
            onion(a,b);
            wyn+=krawedzie[i].c;
        }
    }
    cout << wyn;
    return 0;
}
