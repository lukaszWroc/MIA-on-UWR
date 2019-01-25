#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector< pair<long long int,long long int> >v;
bool cmp(pair<long long int,long long int> &a, pair<long long int,long long int> &b)
{
    if(a.first == b.first)
        return  a.second  < b.second;
    return a.first < b.first;
}
int main()
{
    int n;
    long long int k1,k2;
    cin >> n;
    cin >> k1 >> k2;
    long long int a,b;
    for(int i=0;i<n;i++)
    {
        cin >> a >> b;
        v.push_back(make_pair(a*k1+b,a*k2+b));
    }
    sort(v.begin(),v.end(),cmp);
    bool check = true;
    for(int i=1;i<v.size();i++)
    {
        if(v[i].first != v[i-1].first && v[i-1].second > v[i].second)
        {
            check = false;
            break;
        }
    }
    if(check)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}

