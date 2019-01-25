#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

int tabzer[300100];
int tabmin[300100];
int d,n,k;
char c;
int a,b;
string S;
int pot(int x){
    int y=1;
    while(y<x)
        y*=2;
    return y;

}
void inicjalizuj(){
    for(int i=d-1;i>0;i--){
        tabzer[i]=tabzer[2*i]+tabzer[2*i+1];
        tabmin[i]=tabmin[2*i]+tabmin[2*i+1];
    }
}


void dodaj_z(int x,int y){
    if(y==1)
        tabzer[x]=1;
    else
        tabzer[x]=0;
    x/=2;
    while(x){
        tabzer[x]+=y;
        x/=2;
    }
}
void dodaj_m(int x,int y){
    if(y==1)
        tabmin[x]=1;
    else
        tabmin[x]=0;
    x/=2;
    while(x){
        tabmin[x]+=y;
        x/=2;
    }
}
int ile_m(int l,int p){
    int sum=tabmin[l];
    if(l!=p)
        sum+=tabmin[p];
    while(l/2!=p/2){
        if(l%2==0)
            sum+=tabmin[l+1];
        if(p%2==1)
            sum+=tabmin[p-1];
        l/=2;
        p/=2;
    }
    return sum;
}
int ile_z(int l,int p){
    int sum=tabzer[l];
    if(l!=p)
        sum+=tabzer[p];
    while(l/2!=p/2){
        if(l%2==0)
            sum+=tabzer[l+1];
        if(p%2==1)
            sum+=tabzer[p-1];
        l/=2;
        p/=2;
    }
    return sum;
}
void oblicz_S(){
    for(int i=0;i<k;i++){
        cin >>c>>a>>b;
        if(c=='C'){

            if(b>0){
                if(tabmin[a+d-1] == 1){
                    dodaj_m(a+d-1,-1);
                }
                if(tabzer[a+d-1] == 1){
                    dodaj_z(a+d-1,-1);
                }
            }
            if(b==0){
                if(tabmin[a+d-1] == 1){
                    dodaj_m(a+d-1,-1);
                }
                if(tabzer[a+d-1] == 0){
                    dodaj_z(a+d-1,1);
                }
            }
            if(b<0){
                if(tabmin[a+d-1] == 0){
                    dodaj_m(a+d-1,1);
                }
                if(tabzer[a+d-1] == 1){
                    dodaj_z(a+d-1,-1);
                }
            }
        }
        else{
            if(ile_z(a+d-1,b+d-1) >0)
                S+='0';
            if(ile_m(a+d-1,b+d-1)%2==0 && ile_z(a+d-1,b+d-1) == 0)
                S+='+';
            if(ile_m(a+d-1,b+d-1)%2==1 && ile_z(a+d-1,b+d-1) == 0)
                S+='-';
        }
    }
}
void czysc(){
    S.clear();
    for(int i=0;i<=d+n;i++){
        tabzer[i]=0;
        tabmin[i]=0;
    }
}

void start(){
    cin >> k;
    d=pot(n);
    czysc();
    for(int i=0;i<n;i++){
        cin >> a;
        if(a<0)
            tabmin[i+d]=1;
        if(a==0)
            tabzer[i+d]=1;
    }
    inicjalizuj();
    oblicz_S();
    cout << S << "\n";
}
int main()
{
    int x;
    while(true)
    {
        x=scanf("%d",&n);
        if(x !=  1)
            break;
        start();
    }


    return 0;
}
