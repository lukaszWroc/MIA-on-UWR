#include<iostream>
#include<vector>
const int MAX=500050;
using namespace std;

vector<int>graf[MAX];
int tab[MAX];
bool vis[MAX];
int in[MAX];
int cnt=0;
int spr;
bool czy=false;
void dfs(int x){
    vis[x]=true;
    for(int i=0;i<graf[x].size();i++){
        if(tab[graf[x][i]] == tab[x] && !vis[graf[x][i]])
            dfs(graf[x][i]);
        if(tab[graf[x][i]] != tab[x]){
            if(in[cnt] != 0 && spr!=x)
                czy=true;
            spr=x;
            in[cnt]++;
        }
    }
}
int main(){
    int n,a,b,sum=0;
    cin >> n;
    for(int i=1;i<n;i++){
        cin >> a >> b;
        graf[a].push_back(b);
        graf[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
        cin >> tab[i];
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cnt++;
            dfs(i);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<graf[i].size();j++)
            if(tab[graf[i][j]] != tab[i]){
                sum++;
                break;
            }
    }
    if(czy){
        cout <<"NIE";
        return 0;
    }
    for(int i=0;i<=cnt;i++){
        if(in[i] + 1 == cnt){
            cout <<"TAK";
            return 0;
        }
    }
    cout <<"NIE";
    return 0;
}
