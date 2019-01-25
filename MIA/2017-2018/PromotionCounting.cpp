
#include<iostream>
#include<vector>
#include<algorithm>
const int N=100100;
using namespace std;

vector<int>graf[N];
pair<int,int> tab[N];
vector<int>kolejnosc;
bool vis[N];
int ile_synow[N];
int drzewo[3*N];
int wynik[N];
int poz[N];
void dfs(int x){
    vis[x]=true;
    poz[x]=kolejnosc.size();
    kolejnosc.push_back(x);
    for(int i=0;i<graf[x].size();i++){
        if(!vis[graf[x][i]])
            dfs(graf[x][i]);
    }
    for(int i=0;i<graf[x].size();i++){
        ile_synow[x]+=ile_synow[graf[x][i]];
    }
}
int pot(int x){
    int y=1;
    while(y<x)
        y*=2;
    return y;
}
void dodaj(int x){
    while(x){
        drzewo[x]++;
        x/=2;
    }
}
int ile(int l,int p){
    int sum=drzewo[l];
    if(l!=p)
        sum+=drzewo[p];
    while(l/2!=p/2){
        if(l%2==0)
            sum+=drzewo[l+1];
        if(p%2==1)
            sum+=drzewo[p-1];
        l/=2;
        p/=2;
    }
    return sum;
}
int main(){
    int n,a,d;
    cin >> n;
    d=pot(n);
    for(int i=1;i<=n;i++){
        cin >> tab[i].first;
        tab[i].second=i;
    }
    for(int i=1;i<=n;i++)
        ile_synow[i]=1;
    for(int i=2;i<=n;i++){
        cin >> a;
        graf[a].push_back(i);
    }
    dfs(1);
    sort(tab+1,tab+n+1);
    for(int i=n;i>=1;i--){
        a=tab[i].second;
        wynik[a]=ile(poz[a]+d,poz[a]+d+ile_synow[a]-1);
        dodaj(poz[a]+d);
    }
    for(int i=1;i<=n;i++)
        cout << wynik[i] <<"\n";
    return 0;
}
