/*************************************************************************
    > File Name: B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-07-07 19:18:33
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN],u[MAXN],v[MAXN];
vector<int> G[MAXN];
int color[MAXN];
bool f;
void dfs(int v)
{
    if(!f) return;
    color[v]=1;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(color[to]==1) {f=false; return;}
        if(color[to]==0) dfs(to);
    }
    color[v]=2;
}
bool C(int x)
{
    //printf("%d\n",x);
    f=true;
    memset(color,0,sizeof(color));
    for(int i=1;i<=n;i++) G[i].clear();
    int p=(u[1]-1)%n;if(p<=0) p+=n;
    int q=(v[1]-1)%n;if(q<=0) q+=n;
    //printf("%d %d\n",p,q);
    G[p].push_back(q);
    for(int i=2;i<=x;i++) 
    {
        p=(u[i]-2)%n;
        if(p<=0) p+=n;
        q=(v[i]-2)%n;
        if(q<=0) q+=n;
        //printf("%d %d\n",p,q);
        G[p].push_back(q);
    }
    for(int i=1;i<=n;i++)
    {
        if(color[i]==0)
        {
            dfs(i);
            //printf("%d ",i);
            //if(f) puts("YES"); else puts("NO");
            if(!f) return true;
        }
    }
    return false;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
        scanf("%d%d",&u[i],&v[i]);
    int l=0,r=m+1;
    while(r-l>1)
    {
        int mid=(l+r)/2;
        if(C(mid)) r=mid; else l=mid;
    }
    for(int i=1;i<r;i++) puts("1");
    for(int i=1;i<=m-r+1;i++) puts("0");
    return 0;
}

