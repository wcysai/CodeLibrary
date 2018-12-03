/*************************************************************************
    > File Name: K.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-03 15:00:11
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
ll N,T,K[MAXN],p[MAXN],w[MAXN];
struct lab
{
    ll p,w,id;
};
lab a[MAXN],A[MAXN];
bool cmp(lab x,lab y)
{
    return x.p*y.w<y.p*x.w;
}
struct cl
{
    ll sp,sw;
    vector<int> ord;
};
bool cmp2(cl x,cl y)
{
    return x.sp*y.sw<y.sp*x.sw;
}
cl b[MAXN];
int main()
{
    freopen("student.in","r",stdin);
    freopen("student.out","w",stdout);
    scanf("%lld",&N);T=0;
    for(ll i=1;i<=N;i++) 
    {
        scanf("%lld",&K[i]);
        T+=K[i];
    }
    for(ll i=1;i<=T;i++) {scanf("%lld",&a[i].p); A[i].p=a[i].p;}
    for(ll i=1;i<=T;i++) {scanf("%lld",&a[i].w); A[i].w=a[i].w;}
    for(ll i=1;i<=T;i++) a[i].id=i;
    ll cur=1;
    for(ll i=1;i<=N;i++)
    {
        sort(a+cur,a+cur+K[i],cmp);
        b[i].ord.clear();b[i].sw=0;b[i].sp=0;
        for(ll j=cur;j<cur+K[i];j++) 
        {
            b[i].ord.push_back(a[j].id);
            b[i].sw+=a[j].w;
            b[i].sp+=a[j].p;
        }
        cur+=K[i];
    }
    sort(b+1,b+N+1,cmp2);
    ll ans=0,tot=0;
    vector<ll> ford;ford.clear();
    for(ll i=1;i<=N;i++)
    {
        for(ll j=0;j<(int)b[i].ord.size();j++)
        {
            ll now=b[i].ord[j];
            ford.push_back(now);
            tot+=A[now].p;
            ans+=tot*A[now].w;
        }
    }
    printf("%lld\n",ans);
    for(ll i=0;i<(int)ford.size();i++) printf("%lld%c",ford[i],i==(int)ford.size()-1?'\n':' ');
    return 0;
}

