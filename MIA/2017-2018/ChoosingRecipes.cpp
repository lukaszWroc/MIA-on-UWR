#include<iostream>
#include<vector>
#include<algorithm>
const int MAX =100000000;

using namespace std;

bool mam[1000];
int koszt[1000];
int tab[1000][1000];
vector<int>v;
void zamien(int x){
    while(x){
        if(x%2==1)
            v.push_back(1);
        else
            v.push_back(0);
        x/=2;
    }
}
void zeruj(int r,int p,int m){
    for(int i=0;i<r;i++){
        for(int j=0;j<p;j++){
            tab[i][j] = 0;
        }
    }
    for(int i=0;i<1000;i++){
        mam[i]=false;
    }
    for(int i=0;i<p;i++){
        koszt[i]=0;
    }
}
void start(){
    int r,p,n,m;
    cin >> r >> p >> n >> m;
    zeruj(r,p,m);
    for(int i=0;i<m;i++){
        int a;
        cin >> a;
        mam[a]=true;
    }
    for(int i=0;i<p;i++){
        cin >> koszt[i];
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<p;j++){
            cin >> tab[i][j];
        }
    }
    int d=1<<p;
    int wynof=MAX;
    for(int i=0;i<d;i++){
        v.clear();
        zamien(i);
        int cena=0;
        for(int j=v.size();j<p;j++)
            v.push_back(0);
        for(int j=0;j<v.size();j++)
            if(v[j]==1 && mam[j] == false)
                cena+=koszt[j];

        int tym=r;
        for(int j=0;j<r;j++){
            bool spr =true;
            for(int f=0;f<p;f++){
               if(tab[j][f] == 1 && v[f] == 0){
                    tym--;
                    break;
               }
            }
        }
        if(tym>=n)
            wynof=min(wynof,cena);
    }
    cout << wynof << "\n";
}

int main(){
    int t;
    cin >> t;
    for(int i=0;i<t;i++)
        start();
    return 0;
}
