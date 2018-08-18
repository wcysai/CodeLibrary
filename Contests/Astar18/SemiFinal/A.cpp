/*************************************************************************
    > File Name: A.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-18 14:00:55
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
ll T,n,k,a[MAXN];
ll minx,maxx,minx2,maxx2;
vector<int> G[MAXN];
void dfs(ll v,ll p)
{
    ll cnt1=0,cnt2=0,cnt3=0,cnt4=0;
    for(ll i=0;i<(int)G[v].size();i++)
    {
        ll to=G[v][i];
        if(to==p) continue;
        dfs(to,v);
        if(a[to]>cnt1)
        {
            cnt2=cnt1;
            cnt1=a[to];
        }
        else if(a[to]>cnt2) cnt2=a[to];
        if(a[to]<cnt3)
        {
            cnt4=cnt3;
            cnt3=a[to];
        }
        else if(a[to]<cnt4) cnt4=a[to];
    }
    maxx+=cnt1;minx+=cnt3;
    maxx2=max(maxx2,cnt2);minx2=min(minx2,cnt4);
}
int main()
{
    scanf("%I64d",&T);
    while(T--)
    {
        scanf("%I64d",&n);
        for(ll i=1;i<=n;i++) G[i].clear();
        minx=0;maxx=0;minx2=0;maxx2=0;
        for(ll i=2;i<=n;i++) 
        {
            ll x;
            scanf("%I64d",&x);
            G[x].push_back(i);G[i].push_back(x);
        }
        for(ll i=1;i<=n;i++) scanf("%I64d",&a[i]);
        dfs(1,0);
        maxx+=maxx2;minx+=minx2;
        if(a[1]>0) maxx+=a[1];
        if(a[1]<0) minx+=a[1];
        printf("%I64d %I64d\n",maxx,minx);
    }
    return 0;
}

