#include<iostream>
#include<vector>
using namespace std;
int ile[1001];
int tab[1001][1001];

vector<int>v[3];
int main(){
    int n,m,a,b;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        tab[a][b]=true;
        tab[b][a]=true;
        ile[a]++;
        ile[b]++;
    }
    bool spr=false;
    int size1,size2=-1;
    size1=ile[1];
    v[0].push_back(1);
    for(int i=2;i<=n;i++){
        if(ile[i] == size1){
            v[0].push_back(i);
        }
        else if(ile[i] != size1 && size2==-1){
            size2=ile[i];
            v[1].push_back(i);
        }
        else if(ile[i] == size2){
            v[1].push_back(i);
        }
        else{
            spr =true;
            break;
        }
    }
    if( (size1+1 != v[0].size() || size2+1 != v[1].size() ) && (size2!=-1 || size1*2+2 != v[0].size()))
        spr=true;
    if(!spr)
        cout <<"DA";
    else
        cout <<"NE";

    return 0;
}
