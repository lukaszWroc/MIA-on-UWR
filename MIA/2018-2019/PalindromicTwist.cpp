#include<iostream>
#include<string>
#include<math.h>
using namespace std;

bool check(const string &s)
{
    int d=s.size()/2; //s.size()  is always even
    for(int i=0;i<d;i++)
    {
        int a = s[i];
        int b = s[s.size() - i - 1];
        if(abs(a-b) != 0 && abs(a-b) != 2)
            return 0;
    }
    return 1;
}

int main()
{
    int t;
    cin >> t;
    string s;
    int a;
    for(int i=0;i<t;i++)
    {
        cin >> a >> s;
        if(check(s))
            cout << "YES\n";
        else
            cout << "NO\n";

    }

    return 0;
}

/*

5
6
abccba
2
cf
4
adfa
8
abaazaba
2
ml

*/
