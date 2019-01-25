#include<iostream>
const int DANE= 1000010;
using namespace std;
int pyt[DANE];
long long int fi[DANE],wyn[DANE];
void pre(int n)
{
    fi[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(fi[i]==0)
        {
            fi[i]=i-1;
            for(int j=i*2;j<=n;j+=i)
            {
                if(fi[j]==0)
                    fi[j]=j;
                fi[j]-=fi[j]/i;
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=i*2;j<=n;j+=i)
            wyn[j]+=fi[j/i]*i;
    for(int i=1;i<=n;i++)
        wyn[i]+=wyn[i-1];
}
int main()
{
    int maxn=0,n,ct=0;

    while(true)
    {
        cin >> n;
        if(n==0)
            break;
        pyt[ct++]=n;
        maxn=max(maxn,n);
    }
    pre(maxn);
    for(int i=0;i<ct;i++)
        cout << wyn[pyt[i]] << " ";
}
