#include<bits/stdc++.h>
#define MAXN 1000005
#define MAXM 30000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
vector<int> G[MAXN];
int n,tot,st[MAXN],ed[MAXN];
int f[MAXN],g[MAXN];
int maxi[MAXN];
int cnt[MAXM];
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
void dfs(int v,int p)
{
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
    }
}
void ddfs(int v,int p)
{
    f[v]=0;
    int max1=0,max2=0;
    for(auto to:G[v])
    {
        if(to==p) continue;
        ddfs(to,v);
        if(f[to]+1>max1)
        {
            max2=max1;
            max1=f[to]+1;
        }
        else if(f[to]+1>max2) max2=f[to]+1;
    }
    f[v]=max1;
    for(auto to:G[v])
    {
        if(to==p) continue;
        if(f[to]+1==max1) g[to]=max2+1; else g[to]=max1+1;
    }
}
void rdfs(int v,int p)
{
    for(auto to:G[v])
    {
        if(to==p) continue;
        g[to]=max(g[to],g[v]+1);
        rdfs(to,v);
    }
}
vector<int> vv;
void solve(int v)
{
    printf("v=%d\n",v);
    sort(vv.begin(),vv.end());
    for(auto x:vv) printf("%d ",x);
    puts("");
    int cnt=0,mm=0;
    for(int i=0;i<(int)vv.size();i++)
    {
        cnt++;
        if(i!=0) mm=max(mm,(vv[i]+vv[i-1])/2);
        if(i==(int)vv.size()-1||vv[i]!=vv[i+1])
        {
            maxi[mm]=max(maxi[vv[i]],cnt);
        }
    }
}
void dfs2(int v,int p)
{
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs2(to,v);
    }
    vv.clear();
    for(auto to:G[v])
    {
        if(to==p) continue;
        vv.push_back(f[to]+1);
    }
    if(g[v]) vv.push_back(g[v]);
    solve(v);
}

int main()
{
    scanf("%d",&n);
    tot=n;
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        ++tot;
        add_edge(u,tot); add_edge(v,tot);
    }
    for(int i=1;i<=n;i++) maxi[i]=1;
    dfs(1,0); ddfs(1,0); rdfs(1,0); dfs2(1,0);
    for(int i=1;i<=n;i++) printf("%d %d %d\n",i,f[i],g[i]);
    for(int i=n;i>=1;i--) maxi[i]=max(maxi[i],maxi[i+1]);
    for(int i=1;i<=n;i++) printf("%d ",maxi[i]);
    return 0;
}