#include<iostream>
#include<vector>
const int N = 3010;

using namespace std;

bool d[N];
vector<int> v;
int val(int x)
{
    int sum = 0;
    for(int i=0;i<v.size();i++)
    {
       // cout << x << " " << v[i] << endl;
        if(v[i]>x/2)
            break;
        if(x%v[i] == 0)
            sum++;
    }
    return sum;
}
int cal(int n)
{
    for(int i=2;i<=n;i++)
        if(!d[i])
            v.push_back(i);
    int sum = 0;
    for(int i=2;i<=n;i++)
    {
        if(val(i) == 2)
            sum++;
    }
    return sum;
}
int sieve(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(!d[i])
            for(int j = i+i;j<=n;j+=i)
                d[j] = true;

    }
    return cal(n);
}
int main()
{
    int n;
    cin >> n;
    cout << sieve(n);
    return 0;
}
