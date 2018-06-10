/*************************************************************************
    > File Name: 215.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-10 10:26:43
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
ll tot=0;
vector<int> G[MAXN];
bool used[33];
bool valid[4000][4000];
ll tmp[30];
ll dp[11][4000];
void dfs(ll n,ll id,ll left)
{
    if(id==n)
    {
        for(ll i=0;i<n;i++)
            if(tmp[i]==0) G[tot].push_back(2); else G[tot].push_back(3);
        tot++;
        return;
    }
    if(left>0)
    {
        tmp[id]=1;
        dfs(n,id+1,left-1);
    }
    if(n-id>left)
    {
        tmp[id]=0;
        dfs(n,id+1,left);
    }
}
bool check(ll x,ll y)
{
    memset(used,false,sizeof(used));
    ll s=0;
    for(ll i=0;i<(int)G[x].size();i++)
        s+=G[x][i],used[s]=true;
    s=0;
    for(ll i=0;i<(int)G[y].size()-1;i++)
    {
        s+=G[y][i];
        if(used[s]) return false;
    }
    return true;
}
int main()
{
    for(ll i=0;i<=10;i+=2)
    {
        ll x=i,y=(32-3*i)/2;
        dfs(x+y,0,x);
    }
    printf("%lld\n",tot);
    memset(valid,false,sizeof(valid));
    for(ll i=0;i<tot;i++)
        for(ll j=i;j<tot;j++)
            valid[i][j]=valid[j][i]=check(i,j);
    memset(dp,0,sizeof(dp));
    for(ll i=0;i<tot;i++) dp[1][i]=1;
    for(ll i=2;i<=10;i++)
        for(ll j=0;j<tot;j++)
            for(ll k=0;k<tot;k++)
                if(valid[j][k]) dp[i][j]+=dp[i-1][k];
    ll ans=0;
    for(ll i=0;i<tot;i++) ans+=dp[10][i];
    printf("%lld\n",ans);
    return 0;
}

