/*************************************************************************
    > File Name: E.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-21 22:53:33
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
struct edge
{
    int to,cost;
};
typedef long long ll;
typedef pair<int,int> P;
struct segtree
{
    int val[MAXN];
    void init(int x)
    {
        int p=1;
        while(p<x) p<<=1;
        for(int i=1;i<p*2;i++) val[i]=-INF;
    }
    void update(int k,int x)
    {
    }
    void query(int i)
    {
        int s=-INF;
        while(i>0)
        {
            s=max(s,a[i]);
            i-=i&-i;
        }
    }
}BIT;
int n,l,r;
vector<edge> G[MAXN];
bool centroid[MAXN];
int sz[MAXN];
int d[MAXN];
int dfs(int v,int p)
{
    int c=1;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].to;
        if(to==p||centroid[to]) continue;
        c+=dfs(to,v);
    }
    return sz[v]=c;
}
P dfs2(int v,int p,int t)
{
    P res=P(INT_MAX,-1);
    int s=1,m=0;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i].to;
        if(to==p||centroid[to]) continue;
        res=min(res,dfs2(to,v,t));
        m=max(m,sz[to]);
        s+=sz[to];
    }
    m=max(m,t-s);
    res=min(res,P(m,v));
    return res;
}
int dfs3(int v,int p,int sum,int dep)
{
    int L=l-dep,R=r-dep;
    P maxi=BIT.query()
}

int main()
{
    return 0;
}

