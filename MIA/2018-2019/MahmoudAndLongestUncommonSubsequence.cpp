#include<iostream>
#include<string>

using namespace std;

int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    if(s1 == s2)
        cout << "-1";
    else
        cout << max(s1.size(),s2.size());
    return 0;
}
