#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct zmienne{
    long long int poczatek,koniec;
    int idx;
};

bool cmp(const zmienne& x,const zmienne& y){
    return x.koniec<y.koniec;
}
vector<zmienne>tab;
vector<long long int>dp;

int wyszukaj(long long int x){
    int l=0,p=tab.size()-1,s,odp=0;
    while(l<=p){
        s=(l+p)/2;
        if(tab[s].koniec <= x){
            odp=tab[s].idx;
            l=s+1;
        }
        else
            p=s-1;
    }
    return odp;
}
int main(){
    long long int n;
    int k;
    cin >> n >> k;
    long long int a,b;
    zmienne t;
    for(int i=0;i<k;i++){
        cin >> a >> b;
        t.poczatek=a;
        t.koniec=b;
        tab.push_back(t);
    }
    sort(tab.begin(),tab.end(),cmp);
    int cnt=1;
    tab[0].idx=cnt;
    for(int i=1;i<tab.size();i++){
        if(tab[i].koniec != tab[i-1].koniec){
            cnt++;
        }
        tab[i].idx=cnt;
    }
    dp.resize(cnt+10,0);
    for(int i=0;i<tab.size();i++)
    {
        dp[tab[i].idx] = max( dp[tab[i].idx], max(dp[tab[i].idx-1],
                            dp[wyszukaj(tab[i].poczatek-1LL)] + tab[i].koniec -tab[i].poczatek + 1LL ));
    }

    cout << n - dp[cnt];
    return 0;
}
