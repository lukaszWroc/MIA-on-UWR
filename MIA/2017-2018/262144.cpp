#include<iostream>

using namespace std;
int tab[300000];
int dp[100][300000];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> tab[i];
    for(int i=0;i<70;i++)
        for(int j=0;j<=n;j++)
            dp[i][j]=-1;

    int wyn=0;
    for(int i=0;i<70;i++){
        for(int j=0;j<n;j++){
            if(tab[j] == i){
                dp[i][j] = j+1; // zbior <j,j+1)
                wyn=max(wyn,i);
            }
            else if(i == 0 || dp[i-1][j] == -1 || dp[i-1][dp[i-1][j]] == -1){ // nie ma elementow poprzednich, nie sumuje sie do i-1
                dp[i][j] = -1;
            }

            else{
                dp[i][j] = dp[i-1][dp[i-1][j]]; // suma zbiorow <j,x) + <x,nowy_x)
                wyn=max(wyn,i);
            }
        }
    }
    cout << wyn;
    return 0;
}


