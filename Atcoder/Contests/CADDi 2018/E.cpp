/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-22 20:12:24
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,k,a[MAXN],t;
ll pre[MAXN],suf[MAXN];
P st[MAXN];
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    pre[1]=1;
    t=0;
    for(ll i=2;i<=n;i++)
    {
        if(a[i-1]>=a[i])
        {
            ll dummy=a[i],need=0;
            while(dummy<=a[i-1]) dummy*=4,need++;
            need--;
            if(need>0) st[t++]=P(i,need);
            pre[i]=pre[i-1]+1;
        }
        else
        {
            ll need=0,dummy=a[i-1];
            while(dummy<a[i]) dummy*=4,need++;
            ll pos=i;
            while(t>0&&need>0) 
            {
                pre[i]+=2*need*(pos-st[t-1].F);
                if(st[t-1].S>need) {st[t-1].S-=need; need=0; break;}
                else
                {
                    need-=st[t-1].S;
                    pos=st[t-1].F;
                    t--;
                }
            }
            if(need>0) pre[i]+=2*need*(pos-1);
            pre[i]+=pre[i-1]+1;
        }
    }
    suf[n]=0;
    t=0;
    for(ll i=n-1;i>=1;i--)
    {
        if(a[i+1]>=a[i])
        {
            ll dummy=a[i],need=0;
            while(dummy<=a[i+1]) dummy*=4,need++;
            need--;
            if(need>0) st[t++]=P(i,need);
            suf[i]=suf[i+1];
        }
        else
        {
            ll need=0,dummy=a[i+1];
            while(dummy<a[i]) dummy*=4,need++;
            ll pos=i;
            while(t>0&&need>0) 
            {
                suf[i]+=2*need*(st[t-1].F-pos);
                if(st[t-1].S>need) {st[t-1].S-=need; need=0; break;}
                else
                {
                    need-=st[t-1].S;
                    pos=st[t-1].F;
                    t--;
                }
            }
            if(need>0) suf[i]+=2*need*(n-pos);
            suf[i]+=suf[i+1];
        }
    }
    ll ans=min(suf[1],pre[n]);
    for(ll i=1;i<=n-1;i++) ans=min(ans,pre[i]+suf[i+1]);
    printf("%lld\n",ans);
    return 0;
}

