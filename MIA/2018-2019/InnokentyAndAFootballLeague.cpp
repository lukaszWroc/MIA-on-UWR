#include<iostream>
#include<string>
#include<queue>
#include<vector>
const int N = 1010;
using namespace std;

pair<string,string>tab[N];
bool p[N];
vector<int>t[1000*1000+10];
queue<string>Q;
int number(string a)
{
    return a[0] + a[1] * 100 + a[2] * 10000;
}
void bfs()
{
    string s;
    int x;
    while(!Q.empty())
    {
        s=Q.front();
        Q.pop();
        x = number(s);
        for(int i=0;i<t[x].size();i++)
        {
            int y = t[x][i];
            if(s == tab[y].first && p[y])
            {
                p[y] = false;
                Q.push(tab[y].second);
            }
        }
    }


}
int main()
{
    int n;
    cin >> n;
    string a,b;
    for(int i=0;i<n;i++)
    {
        cin >> a >> b;
        tab[i] = make_pair(a.substr(0,3),a.substr(0,2) + b.substr(0,1));
        int x,y;
        x = number(tab[i].first);
        y = number(tab[i].second);
        t[x].push_back(i);
        t[y].push_back(i);
        p[i] = true;
    }
    bool check = true;
    for(int i=0;i<n;i++)
    {
        a = tab[i]. first;
        for(int j=i+1;j<n;j++)
        {
            if(a == tab[j].first)
            {
                Q.push(a);
                break;
            }
        }
    }
    bfs();
    for(int i=0;i<n;i++)
    {
        if(!p[i])
            tab[i].first = tab[i].second;
    }
    for(int i=0;i<n;i++)
    {
        a = tab[i]. first;
        for(int j=i+1;j<n;j++)
        {
            if(a == tab[j].first)
            {
                check = false;
                break;
            }
        }
        if(!check)
            break;
    }
    if(!check)
    {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for(int i=0;i<n;i++)
        cout << tab[i].first << "\n";

}


