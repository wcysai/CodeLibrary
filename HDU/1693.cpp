/*************************************************************************
    > File Name: 1693.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-30 01:10:01
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 12
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll T,n,m;
ll a[MAXN][MAXN];
unordered_map<ll,ll> mp[MAXN][MAXN];
int main()
{
    scanf("%lld",&T);
    for(ll t=1;t<=T;t++)
    {
        scanf("%lld%lld",&n,&m);
        for(ll i=1;i<=n;i++) for(ll j=0;j<=m;j++) mp[i][j].clear();
        for(ll i=1;i<=n;i++) for(ll j=1;j<=m;j++) scanf("%lld",&a[i][j]);
        mp[1][0][0]=1;
        for(ll i=1;i<=n;i++)
        {
            for(ll j=0;j<m;j++)
            {
                for(auto p:mp[i][j])
                {
                    ll mask=p.F;
                    ll left=(1<<(m-j)),up=(1<<(m-j-1));
                    ll l=(mask/left)%2,r=(mask/up)%2;
                    if(!a[i][j+1])
                    {
                        if(l==0&&r==0) mp[i][j+1][mask]+=p.S;
                        continue;
                    }
                    if(l==0&&r==0)
                    {
                        if(!a[i+1][j+1]||!a[i][j+2]) continue;
                        ll newmask=mask+left+up;
                        mp[i][j+1][newmask]+=p.S;
                    }
                    else if(l==0)
                    {
                        if(a[i][j+2]) mp[i][j+1][mask]+=p.S;
                        ll newmask=mask-up+left;
                        if(a[i+1][j+1]) mp[i][j+1][newmask]+=p.S;
                    }
                    else if(r==0)
                    {
                        if(a[i+1][j+1]) mp[i][j+1][mask]+=p.S;
                        ll newmask=mask-left+up;
                        if(a[i][j+2]) mp[i][j+1][newmask]+=p.S;
                    }
                    else if(l==1&&r==1) 
                    {
                        ll newmask=mask-left-up;
                        mp[i][j+1][newmask]+=p.S;
                    }
                }
            }
            if(i!=n)
            {
                for(auto p:mp[i][m]) 
                {
                    if(p.F%2) continue;
                    mp[i+1][0][p.F>>1]+=p.S;
                }
            }
        }
        printf("Case %lld: There are %lld ways to eat the trees.\n",t,mp[n][m][0]);  
    }
    return 0;
}

