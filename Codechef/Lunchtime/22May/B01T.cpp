#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int sz[MAXN],sum[MAXN];
bool flip[MAXN];
vector<int> G[MAXN];
void dfs(int v,int p)
{
    sz[v]=1; sum[v]=a[v];
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
        sz[v]+=sz[to]; sum[v]+=sum[to];
    }
}
void solve(int v,int p,int need)
{
    if(sum[v]==need) return;
    if(sum[v]==-need) {flip[v]=true; return;}
    int dif=need-a[v];
    for(auto to:G[v])
    {
        if(to==p) continue;
        if(dif<0)
        {
            if(sz[to]&1) {int ndif=(dif&1?dif:dif+1); solve(to,v,max(ndif,min(-sum[to],sum[to]))); dif-=max(ndif,min(sum[to],-sum[to]));}
            else {int ndif=(dif&1?dif+1:dif); solve(to,v,max(ndif,min(sum[to],-sum[to]))); dif-=max(ndif,min(sum[to],-sum[to]));}
        }
        else if(dif>0)
        {
            if(sz[to]&1) {int ndif=(dif&1?dif:dif-1); solve(to,v,min(ndif,max(sum[to],-sum[to]))); dif-=min(ndif,max(sum[to],-sum[to]));}
            else {int ndif=(dif&1?dif-1:dif); solve(to,v,min(ndif,max(sum[to],-sum[to]))); dif-=min(ndif,max(sum[to],-sum[to]));}
        }
        else
        {
            if(sz[to]%2==0) solve(to,v,0);
            else {solve(to,v,1); dif-=1;}
        }
    }  
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            if(a[i]==0) a[i]=-1;
        }
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v); G[v].push_back(u);
        }
        dfs(1,0);
        for(int i=1;i<=n;i++) flip[i]=false;
        solve(1,0,0);
        int cnt=0;
        for(int i=1;i<=n;i++) if(flip[i]) cnt++;
        printf("%d\n",cnt);
        for(int i=1;i<=n;i++) if(flip[i]) printf("%d ",i);
        puts("");
    }
    return 0;
}

