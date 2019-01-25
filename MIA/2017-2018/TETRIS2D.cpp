#include<iostream>
#include<vector>
#include<algorithm>
const int DANE=1000000;
using namespace std;
struct Zmienne{
    int minn,maxx;
};
Zmienne drzewo[3*DANE];
int oblicz_poziom(int l,int p){
    int maxx=max(drzewo[l].minn,drzewo[p].minn);
    while(l/2!=p/2){
        if(l%2==0)
            maxx=max(maxx,max(drzewo[l+1].minn,drzewo[l+1].maxx));
        if(p%2==1)
            maxx=max(maxx,max(drzewo[p-1].minn,drzewo[p-1].maxx));
        l/=2;
        p/=2;
        maxx=max(maxx,max(drzewo[l].minn,drzewo[p].minn));
    }
    while(l){
        l/=2;
        maxx = max(maxx,drzewo[l].minn);
    }
    return maxx;
}
void dodaj(int x,int h){
    drzewo[x].minn=h;
    while(x){
        x/=2;
        int maks=max(max(drzewo[2*x].minn,drzewo[2*x].maxx),max(drzewo[2*x+1].minn,drzewo[2*x+1].maxx));
        drzewo[x].maxx=max(drzewo[x].maxx,maks);
    }
}
void dodaj_poziom(int l,int p,int h){
    dodaj(l,h);
    if(l!=p)
        dodaj(p,h);
    while(l/2!=p/2){
        if(l%2==0)
            dodaj(l+1,h);
        if(p%2==1)
            dodaj(p-1,h);
        l/=2;
        p/=2;
    }
}
int pot(int x){
    int y=1;
    while(y<x)
        y*=2;
    return y;
}
int main(){
    int D,n,x,l,d,wyn=0;
    cin >> D >> n;
    d=pot(D);
    for(int i=0;i<n;i++){
        cin >> l >> x;
        int h=oblicz_poziom(x+d,x+d+l-1);
        dodaj_poziom(x+d,x+d+l-1,h+1);
        wyn=max(wyn,h+1);
    }
    cout <<wyn;

    return 0;
}
