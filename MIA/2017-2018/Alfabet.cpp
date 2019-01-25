#include<iostream>
#include<string>
using namespace std;
string s;
int dp[52];
int main(){
    int c,maxx,dpmaxx,wyn;
    cin >>s;
    for(int i=0;i<s.size();i++)
        dp[i]=1;
    for(int j=0;j<s.size();j++){
        maxx=s[j];
        dpmaxx=0;
        for(int i=j-1;i>=0;i--){
            c=s[i];
            if(c < maxx && dp[i] > dpmaxx)
                dpmaxx=dp[i];
        }
        dp[j] +=dpmaxx;
    }
    wyn=0;
    for(int i=0;i<s.size();i++){
        wyn=max(wyn,dp[i]);
    }
    cout << 26 -wyn;
    return 0;
}
