/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-12 14:10:10
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
ll T,MX,MY,N;
int main()
{
    scanf("%I64d",&T);
    while(T--)
    {
        scanf("%I64d%I64d%I64d",&MX,&MY,&N);
        ll ans=0;
        for(ll i=0;i<N;i++)
        {
            ll x,y;
            scanf("%I64d%I64d",&x,&y);
            ans+=min(min(x,y),min(MX-x,MY-y));
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

