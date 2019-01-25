#include<iostream>

const int N = 100010;

using namespace std;

int tab[N];
int tab1[N];
int t[N];

int main()
{
    int h;
    cin >> h;
    int n = 0;
    for(int i=0;i<=h;i++)
    {
        cin >> tab[i];
        n+=tab[i];
        tab1[i] = tab[i] -1;
    }
    int d;
    bool check = true;
    for(int i=0;i<=h;i++)
    {
        if(tab[i] > 1 && tab[i-1] > 1)
        {
            d = i-1;
            check = false;
            break;
        }
    }
    if(check)
    {
        cout << "perfect";
        return 0;
    }
    cout << "ambiguous\n";
    for(int i=0;i<h;i++)
        t[i] = i;
    int ct = 0;
    for(int i=h;i<n;i++)
    {

        while(tab1[ct] == 0 && ct<h)
            ct++;
        t[i] = ct;
        tab1[ct]--;

    }
    for(int i=0;i<n;i++)
        cout << t[i] << " ";
    cout << endl;
    int x;
    for(int i=h;i<n;i++)
    {
        if(t[i] == d)
        {
            x = i+1;
        }
    }
    for(int i=h;i<n;i++)
    {
        if(t[i] == d+1)
        {
            t[i] = x;
            break;
        }
    }
    for(int i=0;i<n;i++)
        cout << t[i] << " ";
}


