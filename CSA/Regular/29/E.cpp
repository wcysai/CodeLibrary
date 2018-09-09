/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-07 17:04:01
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
int n,k,ans;
int mx[MAXN],dep[MAXN],num[MAXN],sz[MAXN];
vector<int> G[MAXN];
void dfs(int v,int p,int d)
{
    dep[v]=d;sz[v]=1;int now=d,cnt=1;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        dfs(to,v,d+1);
        sz[v]+=sz[to];
        if(mx[to]>now) {now=mx[to]; cnt=1;}
        else if(mx[to]==now) cnt++; 
    }
    mx[v]=now;num[v]=cnt;
}
void solve(int v,int p)
{
    if(num[v]>1) ans+=n; else ans+=n-mx[v];
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
    dfs(1,0,0);
    return 0;
}

