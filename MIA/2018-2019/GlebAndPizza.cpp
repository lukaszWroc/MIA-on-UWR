#include<iostream>
#include<math.h>
using namespace std;
int check(double x,double y,double cr,double r,double d)
{
    if(sqrt(x*x+y*y)+cr>r)
        return 0;
    if(sqrt(x*x+y*y)<r-d+cr)
        return 0;
    return 1;
}
int main()
{
    double r,d;
    cin >> r >> d;
    int n;
    cin >> n;
    double x,y,cr;
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        cin >> x >> y >> cr;
        sum += check(x,y,cr,r,d);
    }
    cout << sum;
    return 0;
}


/*


8 4
7
7 8 1
-7 3 2
0 2 1
0 -2 2
-3 -3 1
0 6 2
5 3 1

10 8
4
0 0 9
0 0 10
1 0 1
1 0 2


*/
