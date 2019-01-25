#include<iostream>
#include<string.h>

const int N = 100100;
using namespace std;
long long int sum[N];
int main()
{
    int n,m;
    string s;
    cin >> s >> n;
    m = s.size();
    for(int i=1;i<m;i++)
        if(s[i-1] == s[i])
            sum[i+1]  = 1;
    for(int i=1;i<=m;i++)
        sum[i] += sum[i-1];
    int a,b;
    for(int i=0;i<n;i++)
    {
        cin >> a >> b;
        cout << sum[b] - sum[a] << "\n";
    }
}

