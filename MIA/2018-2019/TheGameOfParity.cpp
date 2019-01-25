#include<iostream>

using namespace std;


int main()
{
    int n,k,a,even=0,odd=0,lastmove=-1;
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        if(a%2 == 0)
            even++;
        else
            odd++;
    }
    if(n == k)
    {
        if(odd%2 == 0)
            cout << "Daenerys";
        else
            cout << "Stannis";
        return 0;
    }
    if((n-k)%2 ==0)
        lastmove = 1; //Daenerys
    else
        lastmove = 0; //Stannis
    if(lastmove == 0)
    {
        if(k%2 == 0)
        {
            if((n-k)/2>=even || (n-k)/2>=odd)
                cout << "Daenerys";
            else
                cout << "Stannis";
        }
        else
        {
            if((n-k)/2>=odd)
                cout << "Daenerys";
            else
                cout << "Stannis";
        }
    }
    else
    {
        if(k%2 == 0)
        {
            cout << "Daenerys";
        }
        else
        {
            if((n-k)/2<even)
                cout << "Daenerys";
            else
                cout << "Stannis";
        }
    }
    return 0;
}

