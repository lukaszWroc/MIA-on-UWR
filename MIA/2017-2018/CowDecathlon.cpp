#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector< pair<int,int> >bonusy[21];
int punkty[30][30];
int dp[1050000];
int jakiBonus(int x,int y){
    int sum=0;
    for(int i=0;i<bonusy[y].size();i++){
        if(bonusy[y][i].first > dp[x])
            break;
        sum+=bonusy[y][i].second;
    }
    return sum;
}
int main(){
    int n,k,a,b,c;
    cin >> n >> k;
    for(int i=0;i<k;i++)
    {
        cin >> a >> b >> c;
        bonusy[a].push_back(make_pair(b,c));
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
           cin >> punkty[i][j];

    for(int i=1;i<=20;i++)
        sort(bonusy[i].begin(),bonusy[i].end());
    int d = 1 << n;
    int ile_1,t;
    for(int i=0;i<d;i++)
    {
        ile_1 =__builtin_popcount(i);
        for(int j=0;j<n;j++)
        {
            if(i & (1 << j))
            {
                t=dp[i^(1<<j)] + punkty[j+1][ile_1];
                dp[i]=max(dp[i],t);
            }
        }
        dp[i]+= jakiBonus(i,ile_1);
    }
     cout << dp[(1 <<n) -1];
    return 0;
}
