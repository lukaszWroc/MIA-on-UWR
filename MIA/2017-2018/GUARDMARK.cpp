#include<iostream>
#include<vector>
const int MAX =1000000000;
using namespace std;
int tab[30][3];
vector<int>v;
int dp[2000000][3];
bool dobry[2000000];
void zamien(int x){
    while(x){
        if(x%2==1)
            v.push_back(1);
        else
            v.push_back(0);
        x/=2;
    }
}
int main(){
    int n,m,odp=-1;
    cin >> n>> m;
    int d = 1<<n;
    for(int i=0;i<n;i++)
        cin >> tab[i][0] >> tab[i][1] >> tab[i][2];// h w s
    dp[0][2]=MAX;
    dobry[0]=true;
    for(int i=1;i<d;i++)
    {
        v.clear();
        zamien(i);
        for(int j=0;j<v.size();j++)
        {
            if(v[j]==1)
            {
                int mask = i - (1<<j);
                if(!dobry[mask])
                    continue;
                if(tab[j][2] >= dp[mask][1]){
                    dobry[i]=true;
                    dp[i][2] = max(dp[i][2],min(tab[j][2]-dp[mask][1],dp[mask][2]));
                    dp[i][1] = max(dp[i][1],dp[mask][1] + tab[j][1]);
                    dp[i][0] = max(dp[i][0],dp[mask][0] + tab[j][0]);
                }
                if(m<=dp[i][0])
                    odp=max(odp,dp[i][2]);
            }
        }
    }
    if(odp!=-1)
        cout << odp;
    else
        cout << "Mark is too tall";
    return 0;
}
