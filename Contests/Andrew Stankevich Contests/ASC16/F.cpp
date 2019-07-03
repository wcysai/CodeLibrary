/*************************************************************************
    > File Name: 1519.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-10-29 23:39:06
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 105
#define MAXM 11
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m;
char grid[MAXN][MAXM];
unordered_map<ll,ll> mp[MAXN][MAXM];
int main()
{
    freopen("pipe.in","r",stdin);
    freopen("pipe.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    if(n<m) swap(n,m);
    for(ll i=1;i<=n;i++) 
        for(ll j=1;j<=m;j++)
            grid[i][j]='.';
    ll x=n,y=m;
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=m;j++)
        {
            if(grid[i][j]=='.')
            {
                x=i;y=j;
            }
        }
    mp[1][0][0]=1;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=0;j<m;j++)
        {
            for(auto p:mp[i][j])
            {
                ll mask=p.F;
                ll left=(1<<(2*(m-j))),up=(1<<(2*(m-j-1)));
                ll l=(mask/left)%4,r=(mask/up)%4;
                if(grid[i][j+1]!='.')
                {
                    if(l==0&&r==0) mp[i][j+1][mask]+=p.S;
                    continue;
                }
                if(l==0&&r==0)
                {
                    if(grid[i+1][j+1]!='.'||grid[i][j+2]!='.') continue;
                    ll newmask=mask+left+2*up;
                    mp[i][j+1][newmask]+=p.S;
                }
                else if(l==0)
                {
                    if(grid[i][j+2]=='.') mp[i][j+1][mask]+=p.S;
                    ll newmask=mask-r*up+r*left;
                    if(grid[i+1][j+1]=='.') mp[i][j+1][newmask]+=p.S;
                }
                else if(r==0)
                {
                    if(grid[i+1][j+1]=='.') mp[i][j+1][mask]+=p.S;
                    ll newmask=mask-l*left+l*up;
                    if(grid[i][j+2]=='.') mp[i][j+1][newmask]+=p.S;
                }
                else if(l==1&&r==1)
                {
                    ll cur=1;
                    bool f=false;
                    for(ll k=2*(m-j-2);k>=0;k-=2)
                    {
                        if((mask>>k)%4==1) cur++;
                        if((mask>>k)%4==2) cur--;
                        if(!cur) 
                        {
                            ll newmask=mask-l*left-r*up-(1<<k);
                            mp[i][j+1][newmask]+=p.S;
                            f=true;
                            break;
                        }
                    }
                    assert(f);
                }
                else if(l==2&&r==2)
                {
                    ll cur=1;
                    bool f=false;
                    for(ll k=2*(m-j+1);k<=2*m;k+=2)
                    {
                        if((mask>>k)%4==2) cur++;
                        if((mask>>k)%4==1) cur--;
                        if(!cur) 
                        {
                            ll newmask=mask-l*left-r*up+(1<<k);
                            mp[i][j+1][newmask]+=p.S;
                            f=true;
                            break;
                        }
                    }
                    assert(f);
                }
                else if(l==2&&r==1) 
                {
                    ll newmask=mask-l*left-r*up;
                    mp[i][j+1][newmask]+=p.S;
                }
                else if(l==1&&r==2)
                {
                    if(i==x&&j==y-1)
                    {
                        ll newmask=mask-l*left-r*up;
                        mp[i][j+1][newmask]+=p.S;
                    }
                }
            }
        }
        if(i!=n)
        {
            for(auto p:mp[i][m]) 
            {
                if(p.F%4) continue;
                mp[i+1][0][p.F>>2]+=p.S;
            }
        }
    }
    printf("%lld\n",mp[n][m][0]);
    return 0;
}
