#include<iostream>

using namespace std;

long long int szybpot(long long int a,long long int b,long long int p)
{
    long long int x=1LL;
    while(b>0)
    {
        if(b%2LL==1LL)
        {
            x*=a;
            x%=p;
        }
        a*=a;
        a%=p;
        b/=2LL;
    }
    return x;
}
void start()
{
    long long int n,k,p;
    cin >> n>> k>> p;
    long long int licznik=1LL;
    for(int i=n;i>n-k;i--)
    {
        licznik*=i;
        licznik%=p;
    }
    long long int K=1;
    for(int i=1;i<=k;i++)
    {
        K*=i;
        K%=p;
    }
    long long int mianownik = szybpot(K,p-2,p);
    long long int wynik = (licznik * mianownik)%p;
    cout << wynik << "\n";
}

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
        start();
    return 0;
}
