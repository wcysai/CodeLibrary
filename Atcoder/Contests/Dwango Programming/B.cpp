/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-11-29 13:26:41
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define MAXM 520000
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll b[MAXN],a[MAXM],n,K,tot;
bool valid[MAXM];
int main()
{
    scanf("%lld%lld",&n,&K);
    for(ll i=1;i<=n;i++) scanf("%lld",&b[i]);
    for(ll i=1;i<=n;i++)
    {
        ll s=0;
        for(ll j=i;j<=n;j++) {s+=b[j]; a[++tot]=s;}
    }
    memset(valid,true,sizeof(valid));
    ll ans=0;
    for(ll j=40;j>=0;j--)
    {
        ll cnt=0;
        for(ll i=1;i<=tot;i++)
        {
            if(!valid[i]) continue;
            if(a[i]&(1LL<<j)) cnt++;
        }
        if(cnt>=K) 
        {
            for(ll i=1;i<=tot;i++) if(!(a[i]&(1LL<<j))) valid[i]=false;
            ans+=(1LL<<j);
        }
    }
    printf("%lld\n",ans);
    return 0;
}

