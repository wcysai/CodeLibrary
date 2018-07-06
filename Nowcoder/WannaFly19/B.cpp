/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-06 19:26:53
 ************************************************************************/

#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,x,y,z,a[MAXN][MAXN],zero[MAXN][MAXN],sz[MAXN][MAXN];
ll sum[MAXN][MAXN];
ll curs[MAXN],curz[MAXN];
int main()
{
    scanf("%lld%lld%lld%lld%lld",&n,&m,&x,&y,&z);
    memset(a,0,sizeof(a));memset(zero,0,sizeof(zero));
    memset(sz,0,sizeof(sz));memset(sum,0,sizeof(sum));
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=m;j++)
        {
            scanf("%lld",&a[i][j]);
            zero[i][j]=(a[i][j]==0?1:0);
        }
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=m;j++)
        {
            sum[i][j]=sum[i-1][j]+a[i][j];
            sz[i][j]=sz[i-1][j]+zero[i][j];
        }
    ll ans=0;
    list<ll> q;
    for(ll i=1;i<=n;i++)
        for(ll j=i+1;j<=min(n,i+x-1);j++)
        {
            while(!q.empty()) q.pop_back();
            q.push_front(0LL);
            for(ll k=1;k<=m;k++)
            {
                curs[k]=curs[k-1]+sum[j][k]-sum[i-1][k];
                curz[k]=curz[k-1]+sz[j][k]-sz[i-1][k];
                //printf("%lld %lld %lld %lld\n",i,j,curs[k],curz[k]);
                while(!q.empty()&&curs[q.front()]>curs[k]) q.pop_front();
                q.push_front(k);
                while(!q.empty()&&(k-q.back()>y||curz[k]-curz[q.back()]>z)) q.pop_back();
                ans=max(ans,curs[k]-curs[q.back()]);
            }
        }
    printf("%lld\n",ans);
    return 0;
}

