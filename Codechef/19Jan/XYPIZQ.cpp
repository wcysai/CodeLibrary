#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll T,N,t,x,y,z;
int main()
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld%lld%lld%lld",&N,&t,&x,&y,&z);
        ll p,q=2*N+1;
        if(t==1)
        {
            if(y>x)
            {
                if(z<y) p=z; else p=q-z;
            }
            else
            {
                if(z>y) p=z; else p=q-z;
            }
        }
        else if(t==2||t==4)
        {
            if(y>x)
            {
                if(z<y) p=0; else p=q-2*y;
            }
            else 
            {
                if(z>y) p=0; else p=q-2*y;
            }
        }
        else 
        {
            if(y>x)
            {
                if(z>y) p=q-x; else p=x;
            }
            else
            {
                if(z>y) p=x; else p=q-x;
            }
        }
        ll g=__gcd(p,q);p/=g;q/=g;
        printf("%lld %lld\n",p,q);
    }
    return 0;
}

