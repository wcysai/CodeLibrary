/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-03 15:47:51
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n;
struct dragon
{
    ll a,b;
};
dragon f[MAXN];
bool cmp(dragon x,dragon y)
{
    return max(x.a,x.b+y.a)<max(y.a,y.b+x.a);
}
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld%lld",&f[i].a,&f[i].b);
    sort(f+1,f+n+1,cmp);
    ll ans=0,cur=0;
    for(ll i=1;i<=n;i++)
    {
        ans=max(ans,cur+f[i].a);
        cur+=f[i].b;
    }
    printf("%lld\n",ans);
    return 0;
}

