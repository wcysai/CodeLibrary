/*************************************************************************
    > File Name: 11E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-08 17:06:49
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
int n,sz[MAXN];
vector<int> G[MAXN];
int fact[MAXN],invf[MAXN],inv[MAXN];
int ans;
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
void dfs(int v,int p)
{
    int cnt=1;
    for(int i=0;i<(int)G[v].size();i++)
    {
        if(G[v][i]==p) continue;
        dfs(G[v][i],v);
        cnt+=sz[G[v][i]];
    }
    sz[v]=cnt;
}
void solve(int v,int p,int now)
{
    ans=(ans+now)%MOD;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        solve(to,v,(1LL*now*sz[to]%MOD)*inv[(n-sz[to])]%MOD);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    fact[0]=invf[0]=inv[1]=1;
    for(int i=1;i<=n;i++)
        fact[i]=1LL*fact[i-1]*i%MOD;
    invf[n]=pow_mod(fact[n],MOD-2);
    for(int i=n-1;i>=1;i--)
    {
        invf[i]=1LL*invf[i+1]*(i+1)%MOD;
        inv[i+1]=1LL*invf[i+1]*fact[i]%MOD;
    }
    dfs(1,0);
    int res=fact[n];
    for(int i=1;i<=n;i++)
        res=1LL*res*inv[sz[i]]%MOD;
    solve(1,0,res);
    printf("%d\n",ans);
    return 0;
}

