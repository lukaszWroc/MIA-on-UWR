#include<iostream>
#include<stack>

using namespace std;

void start()
{
    long long int s,n,x;
    long long int minn=10000000;
    cin >> n >> s;
    stack<long long int>q,minq;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        if(x>=0)
        {
            q.push(x);
            if(minq.empty())
                minq.push(x);
            else
            {
                minn=minq.top();
                minn=min(minn,x);
                minq.push(minn);
            }

        }
        else
        {
            if(!minq.empty() && x*-1<minq.top())
                s-=(x*-1);
            else{
                long long int sum=x*-1;
                while(!q.empty())
                {
                    long long int a;
                    a=q.top();
                    q.pop();
                    minq.pop();
                    sum-=a;
                    if(sum<=0)
                    {
                        s+=(sum*-1);
                        break;
                    }
                }
                if(sum>0)
                    s-=sum;
            }
        }
    }
    long long int wyn=0;
    while(!q.empty())
    {
        x=q.top();
        q.pop();
        wyn+=x;
    }
    cout << s << " " << wyn << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int i=0;i<T;i++)
    {
        start();
    }
    return 0;
}
