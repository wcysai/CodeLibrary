/*************************************************************************
    > File Name: C.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-22 19:58:47
 ************************************************************************/

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
ll n,p;
int main()
{
    scanf("%lld%lld",&n,&p);
    if(n==1)
    {
        printf("%lld\n",p);
        return 0;
    }
    else if(n>=40)
    {
        printf("%lld\n",1LL);
        return 0;
    }
    else
    {
        bool f=true;
        ll ans=-1;
        for(ll i=1;i<=1000000;i++)
        {
            ll s=1;
            for(ll j=1;j<=n;j++)
            {
                s=s*i;
                if(s>p) {f=false; break;}
            }
            if(!f) break;
            if(p%s==0) ans=i;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

