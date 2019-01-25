#include<iostream>

const int N = 1000010;

using namespace std;
long long int tabn[N];
long long int tabm[N][3];
long long int tabk[N];
long long int tabks[N];
long long int tabmm[N];
int suf(long long int tab[],long long int tabs[],int n)
{
    long long int sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=tab[i];
        tabs[i]+=sum;
    }
}
int main()
{
    int n,m,k;
    cin >> n >> m >>k;

    for(int i=1;i<=n;i++)
        cin >> tabn[i];
    long long int a,b,c;
    for(int i=0;i<m;i++)
    {
        cin >> tabm[i][0] >> tabm[i][1] >> tabm[i][2];
    }
    for(int i=0;i<k;i++)
    {
        cin >> a >> b;
        tabk[a]++;
        tabk[b+1]--;
    }
    suf(tabk,tabks,m);
   /* cout << endl;
    for(int i=1;i<=m;i++)
        cout << tabks[i] << " ";
    cout << endl;*/
    for(int i=0;i<m;i++)
    {
        a=tabm[i][0];
        b=tabm[i][1];
        c=tabm[i][2];
        tabmm[a] += tabks[i+1]*c;
        tabmm[b+1] -= tabks[i+1]*c;
     //   cout << "* " << a << " " << b << endl;
    }
   /* cout << endl;
    for(int i=0;i<=n;i++)
        cout << tabmm[i] << " ";
    cout << endl;*/
    suf(tabmm,tabn,n);
    for(int i=1;i<=n;i++)
    {
        cout << tabn[i] << " ";
    }
}



/*


3 3 3
1 2 3
1 2 1
1 3 2
2 3 4
1 2
1 3
2 3


4 3 6
1 2 3 4
1 2 1
2 3 2
3 4 4
1 2
1 3
2 3
1 2
1 3
2 3

*/
