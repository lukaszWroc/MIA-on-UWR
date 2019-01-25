#include<iostream>
#include<algorithm>
#include<vector>
const int MAX =100100;
const int INF=2000000000;
using namespace std;
int tab[2*MAX];
pair<int,int>tabs[2*MAX];
vector<int>tree[4*MAX];
int d;
int wyszukajl(int v,int k){
    int l=0,p=tree[v].size()-1,s,wyn=0;
    while(l<=p){
        s=(l+p)/2;
        if(tree[v][s] <= k){
            wyn=s;
            l=s+1;
        }
        else
            p=s-1;
    }
    return wyn;
}
int wyszukajp(int v,int k){
    int l=0,p=tree[v].size()-1,s,wyn=0;
    while(l<=p){
        s=(l+p)/2;
        if(tree[v][s] >= k){
            wyn=s;
            p=s-1;
        }
        else
            l=s+1;
    }
    return wyn;
}
int ile(int v,int l,int p){
    int wl=wyszukajl(v,l);
    int wp=wyszukajl(v,p);
    int sum=0;
    if(tree[v][wl] >= l)
        sum++;
    if(tree[v][wp] <= p)
        sum++;
    if(sum==0)
        sum=-1;
    if(sum==2)
        sum=1;
    else
        sum=0;
    return wp-wl+sum;
}
int odp(int l,int p,int k){
    int v=1,sum=0;
    while(true){
        if( d<=v && v < 2*d)
            break;
        if(ile(2*v,l,p)+sum < k){
            sum+=ile(2*v,l,p);
            v=2*v+1;
        }
        else
            v=2*v;
    }
    return tab[tree[v][0]];

}
int pot(int x){
    int y=1;
    while(y<x)
        y*=2;
    return y;
}
int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int n,q,a,b,c;
    cin >> n >> q;
    d=pot(n);
    for(int i=0;i<n;i++)
    {
        cin >> tab[i];
        tabs[i].first=tab[i];
        tabs[i].second=i;
    }
    sort(tabs,tabs+n);
    for(int i=n;i<d;i++)
    {
        tabs[i].first=INF;
        tabs[i].second=i;
    }
    for(int i=0;i<d;i++)
        tree[d+i].push_back(tabs[i].second);
    for(int i=d-1;i>0;i--)
    {
        for(int j=0;j<tree[2*i].size();j++)
        {
            tree[i].push_back(tree[2*i][j]);
            tree[i].push_back(tree[2*i+1][j]);
        }
        sort(tree[i].begin(),tree[i].end());
    }
    for(int i=0;i<q;i++)
    {
        cin >> a >> b >> c;
        cout << odp(a-1,b-1,c) << "\n";
    }
    return 0;
}
