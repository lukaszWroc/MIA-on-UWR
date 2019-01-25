#include<iostream>

 using namespace std;

 bool answ(int n)
 {
     if(n>3)
        return 0;
     if(n == 1)
        cout << 1;
     if(n == 2)
        cout << 2;
     if(n == 3)
        cout << 6;
     return 1;
 }
 int main()
 {
     int n;
     cin >> n;

    if(answ(n))
         return 0;
    long long int n1 = static_cast<long long int>(n);
    if(n%2 == 1)
        cout << n1*(n1-1)*(n1-2);
    else
    {
        long long int maxx = 0;
       // for(int i=0;i<=n;i++)
       /// {
           // long long int i1 = static_cast<long long int>(i);
        if(n%3 != 0)
            maxx = n1*(n1-1)*(n1-3);
        else
            maxx = max(n1*(n1-1)*(n1-5),(n1-3)*(n1-1)*(n1-2));
       // }
        cout << maxx;
    }

 }
