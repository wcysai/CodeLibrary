/*************************************************************************
    > File Name: 622.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-13 21:20:25
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 50000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main()
{
    ll ans=0,t=1;
    for(ll i=1;i<=60;i++) t*=2;
    t--;
    printf("%lld\n",t);
    for(ll i=0;(2*i+1)*(2*i+1)<=t;i++)
    {
        ll x=2*i+1;
        if(t%x==0)
        {
            bool f=true;
            ll now=1;
            for(ll j=1;j<=59;j++)
            {
                now*=2;
                if((now-1)%x==0)
                {
                    f=false;
                    break;
                }
            }
            if(f)
            {
                printf("%lld\n",x);
                ans+=x+1;
            }
            x=t/x;
            f=true;
            now=1;
            for(ll j=1;j<=59;j++)
            {
                now*=2;
                if((now-1)%x==0)
                {
                    f=false;
                    break;
                }
            }
            if(f)
            {
                printf("%lld\n",x);
                ans+=x+1;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}

