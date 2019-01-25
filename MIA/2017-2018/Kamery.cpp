#include<iostream>
#include<string>
using namespace std;
int tab[100010];
int main(){
    int n,k,r,a;
    cin >> n >> k>> r;
    for(int i=0;i<k;i++)
    {
        cin >> a;
        tab[a]=1;
    }
    int ile=0;
    for(int i=1;i<=r;i++)
    {
        if(tab[i]==1)
            ile++;
    }
    int wynik=0;
    if(ile==0)
    {
        tab[r]=1;
        tab[r-1]=1;
        ile=2;
        wynik=2;
    }
    if(ile==1){
        if(tab[r]==1)
            tab[r-1]=1;
        else
            tab[r]=1;
        ile=2;
        wynik=1;
    }

    for(int i=r+1;i<=n;i++)
    {
        if(tab[i-r]==1)
            ile--;
        if(tab[i]==1)
            ile++;
        if(ile<2){
            wynik++;
            tab[i]=1;
            ile++;
        }
    }
    cout << wynik;
    return 0;
}
