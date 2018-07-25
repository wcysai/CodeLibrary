/*************************************************************************
    > File Name: H.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-24 23:28:55
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
int n,m,q,C;
vector<int> G[MAXN];
int dep[MAXN],c[MAXN],f[MAXN];
double prob[MAXN],E[MAXN];
void dfs(int v,int d)
{
    dep[v]=d;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        dfs(to,d+1);
    }
}
int main()
{
    scanf("%d%d%d%d",&n,&m,&q,&C);
    for(int i=1;i<=n;i++) scanf("%d",&f[i]);
    for(int i=2;i<=n;i++) 
    {
        int v;scanf("%d",&v);
        G[v].push_back(i);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) prob[i]=(double)(dep[i]+1)/n;
    for(int i=1;i<=m;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n;i++) E[f[i]]+=prob[i]*c[i];
    for(int i=1;i<=q;i++)
    {
        int type,x,y;
        scanf("%d",&type);
        if(type==1)
        {
            scanf("%d%d",&x,&y);
            E[f[x]]-=prob[x]*c[x];
            f[x]=y;
            E[f[x]]+=prob[x]*c[x];
        }
        else
        {
            scanf("%d",&x);
            printf("%.10lf\n",E[x]*E[x]-2*C*E[x]+C*C);
        }
    }
    return 0;
}

