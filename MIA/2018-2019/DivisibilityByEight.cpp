#include<iostream>
#include<string>
const int N = 101;

using namespace std;

int dp[N][8];
int p[N][8];

void cal(const string &s)
{
    for(int i=1;i<s.size();i++)
    {
        int x = s[i]-'0';
        dp[i][x%8] = 1;
        p[i][x%8] = -1;
        for(int j=0;j<8;j++)
        {
            if(dp[i-1][j]==1)
            {
                if(dp[i][(j*10 + x)%8]==0)
                {
                    dp[i][(j*10+x)%8]=1;
                    p[i][(j*10+x)%8]=j;
                }
                if(dp[i][j] == 0)
                {
                    dp[i][j]=1;
                    p[i][j]=j;
                }
            }
        }
    }
}

void path(const string &s,int i,int j)
{
    if(p[i][j]==-1) // end of the path
    {
        cout<<s[i];
        return;
    }
    int k = p[i][j] ;
    path(s,i-1,k) ;
    int x = s[i]-'0';
    if((k*10+x)%8 == j)
        cout<<s[i] ;
}

void ans(const string &s)
{
    for(int i=0;i<s.size();i++)
    {
        if(dp[i][0] == 1)
        {
            cout << "YES\n";
            path(s,i,0);
            return;
        }
    }
    cout << "NO";
}
int main()
{
    string s;
    cin >> s;
    dp[0][(s[0]-'0')%8]=1;
    p[0][(s[0]-'0')%8]=-1;
    cal(s);
    ans(s);
    return 0;
}


