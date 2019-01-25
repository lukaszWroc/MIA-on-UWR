#include<stdio.h>


int ostatni_licznik,ostatni_mianownik;

double oblicz(int x,double y){
    double wyn=y;
    for(int i=0;i<x;i++){
        if(ostatni_licznik == 0)
            return 0.f;
        wyn*=(double)ostatni_licznik/ostatni_mianownik;
        ostatni_licznik--;
        ostatni_mianownik--;
    }
    return wyn;
}

int pot(int y){
    int z=1;
    while(y>0){
        z*=2;
        y--;
    }
    return z;
}
int main(){
    int k,r;
    double wynik=0,wynik_t=1;
    scanf("%d%d", &k,& r);
    ostatni_mianownik=pot(k)-1;
    ostatni_licznik=pot(k)-r;
    int t=1;
    while(1){
        wynik_t=oblicz(t,wynik_t);
        wynik+=wynik_t;
         if(ostatni_licznik==0)
            break;
        t*=2;
    }
    printf("%.5f",wynik);
    return 0;
}
