/*************************************************************************
    > File Name: 1131.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-04 20:41:29
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
vector<int> G[MAXN];
int sz[MAXN];
ll dp[MAXN];
inline char nc()
{
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
inline int _read()
{
    char ch=nc();int sum=0;
    while(!(ch>='0'&&ch<='9'))ch=nc();
    while(ch>='0'&&ch<='9')sum=sum*10+ch-48,ch=nc();
    return sum;
}
void dfs1(int v,int p)
{
    sz[v]=1;dp[v]=0;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        dfs1(to,v);
        dp[v]+=dp[to];sz[v]+=sz[to];
    }
    dp[v]+=(sz[v]-1);
}
void dfs2(int v,int p)
{
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        dp[to]=dp[v]+sz[1]-2*sz[to];
        dfs2(to,v);
    }
}
int main()
{
    n=_read();
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        u=_read();v=_read();
        G[v].push_back(u);G[u].push_back(v);
    }
    dfs1(1,0);dfs2(1,0);
    //for(int i=1;i<=n;i++) printf("%intd\n",dp[i]);
    ll ans=0;
    int id=-1;
    for(int i=1;i<=n;i++) if(dp[i]>ans) {ans=dp[i]; id=i;}
    printf("%d\n",id);
    return 0;
}

