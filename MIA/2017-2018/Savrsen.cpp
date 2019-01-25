#include<iostream>
#include<vector>

using namespace std;
bool vis[1000100];
vector<int>dzielniki[1000100];
int pot(int x,int y){
    int wyn=x;
    for(int i=1;i<y;i++)
        wyn*=x;
    return wyn;
}
int main(){
    int a,b,tym,d,ile;
    long long int wynik=0,tym1;
    cin >> a >> b;
    for(int i=2;i<=1000;i++){
        if(!vis[i]){
            for(int j=i+i;j<=1000000;j+=i){
                vis[j]=true;
                dzielniki[j].push_back(i);
            }
        }
    }
    for(a;a<=b;a++){
        tym=a;
        if(vis[a]){
            tym1=1LL;
            for(int i=0;i<dzielniki[a].size();i++){
                d=dzielniki[a][i];
                ile=1;
                while(tym%d==0){
                    tym/=d;
                    ile++;
                }
                tym1*=((pot(d,ile)-1)/(d-1));
            }
            if(tym!=1)
                tym1*=(tym+1);
            wynik+=max(tym1-2*a,2*a-tym1);
        }
        else{
            if(a==1)
                wynik+=1;
            else
                wynik+=a-1;
        }
    }
    cout << wynik << endl;
    return 0;
}


