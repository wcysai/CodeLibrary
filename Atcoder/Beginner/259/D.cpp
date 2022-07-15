#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x[MAXN],y[MAXN],r[MAXN],sx,sy,tx,ty;
bool vis[MAXN];
vector<int> G[MAXN];
bool intersect(int i,int j)
{
    ll d2=1LL*(x[i]-x[j])*(x[i]-x[j])+1LL*(y[i]-y[j])*(y[i]-y[j]);
    if(1LL*(r[i]+r[j])*(r[i]+r[j])<d2) return false;
    int dr=max(r[i],r[j])-min(r[i],r[j]);
    if(1LL*dr*dr>d2) return false;
    return true;
}
void dfs(int v)
{
    vis[v]=true;
    for(auto to:G[v]) if(!vis[to]) dfs(to);
}
bool oncirc(int i,int cx,int cy)
{
    return 1LL*r[i]*r[i]==1LL*(cx-x[i])*(cx-x[i])+1LL*(cy-y[i])*(cy-y[i]);
}
int main()
{
    scanf("%d",&n);
    scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
    for(int i=1;i<=n;i++) scanf("%d%d%d",&x[i],&y[i],&r[i]);
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(intersect(i,j)) {G[i].push_back(j); G[j].push_back(i);}
    for(int i=1;i<=n;i++) if(oncirc(i,sx,sy)) dfs(i);
    bool f=false;
    for(int i=1;i<=n;i++) if(oncirc(i,tx,ty)&&vis[i]) f=true;
    if(f) puts("Yes"); else puts("No");
    return 0;
}

