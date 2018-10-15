/*************************************************************************
    > File Name: ACQUIRE.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-15 09:39:02
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
typedef pair<ll,ll> P;
ll N,tot,t,now;
P arr[MAXN],a[MAXN];
ll dp[MAXN];
P st[MAXN];
ll get(P u,P v) {return (v.S-u.S)/(u.F-v.F);}
void add(ll v)
{
    P p=P(a[v].F,dp[v-1]);
    while(t-now>1&&get(st[t-1],p)<=get(st[t-1],st[t-2])) t--;
    st[t++]=p;
}
int main()
{
    scanf("%lld",&N);
    for(ll i=1;i<=N;i++) scanf("%lld%lld",&arr[i].F,&arr[i].S);
    sort(arr+1,arr+N+1);
    for(ll i=N;i>=1;i--)
        if(i==N||arr[i].S>a[tot].S) a[++tot]=arr[i];
    //puts("");
    //for(ll i=1;i<=tot;i++) printf("%lld %lld\n",a[i].F,a[i].S);
    for(ll i=1;i<=tot;i++)
    {
        add(i);
        while(t-now>1&&get(st[now],st[now+1])<a[i].S) now++;
        //printf("%lld %lld %lld %lld\n",now,t,st[now].F,st[now].S);
        dp[i]=st[now].F*a[i].S+st[now].S;
    }
    printf("%lld\n",dp[tot]);
    return 0;
}

