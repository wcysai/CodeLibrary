#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define MAXLOGN 18
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,q,k,a[MAXN];
vector<int> G[MAXN];
int pa[MAXLOGN][MAXN];
int depth[MAXN];
void dfs(int v,int p,int d)
{
    pa[0][v]=p;
    depth[v]=d;
    for(int i=0;i<(int)G[v].size();i++)
        if(G[v][i]!=p) dfs(G[v][i],v,d+1);
}
void init(int V)
{
    dfs(1,0,0);
    for(int k=0;k+1<MAXLOGN;k++)
    {
        for(int v=1;v<=V;v++)
        {
            if(pa[k][v]<0) pa[k+1][v]=-1;
            else pa[k+1][v]=pa[k][pa[k][v]];
        }
    }
}
int get(int v,int x)
{
    for(int k=0;k<MAXLOGN;k++)
        if((x>>k)&1)
            v=pa[k][v];
    return v;
}
int lca(int u,int v)
{
    if(depth[u]>depth[v]) swap(u,v);
    v=get(v,depth[v]-depth[u]);
    if(u==v) return u;
    for(int k=MAXLOGN-1;k>=0;k--)
    {
        if(pa[k][u]!=pa[k][v])
        {
            u=pa[k][u];
            v=pa[k][v];
        }
    }
    return pa[0][u];
}
int dis(int u,int v)
{
    return depth[u]+depth[v]-2*depth[lca(u,v)];
}
bool cmp(int x,int y)
{
    return depth[x]>depth[y];
}
vector<int> d;
vector<int> tmp[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]); d.push_back(a[i]);}
    sort(d.begin(),d.end());
    d.erase(unique(d.begin(),d.end()),d.end());
    if(d.size()==n) {printf("%d\n",n); return 0;}
    for(int i=1;i<=n;i++)
    {
        int id=lower_bound(d.begin(),d.end(),a[i])-d.begin()+1;
        tmp[id].push_back(i);
    }
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    init(n);
    int sz=(int)d.size();
    int u=-1,v=-1;
    bool f=true;
    for(int i=1;i<=sz;i++)
    {
        if((int)tmp[i].size()>1)
        {
            for(int j=1;j<(int)tmp[i].size();j++)
            {
                int uu=tmp[i][0],vv=tmp[i][j];
                if(u==-1||v==-1) {u=uu; v=vv; continue;}
                if(!f) continue;
                int l1=lca(u,v),l2=lca(uu,vv);
                int t1=lca(l1,uu),t2=lca(l1,vv),t3=lca(l2,u),t4=lca(l2,v);
                f=false;
                if((t1==l1&&depth[t1]>=depth[l2])||(t2==l1&&depth[t2]>=depth[l2])) f=true;
                if((t3==l2&&depth[t3]>=depth[l1])||(t4==l2&&depth[t4]>=depth[l1])) f=true;
                if(!f) continue;
                int a[4];
                a[0]=lca(u,vv);a[1]=lca(u,uu);a[2]=lca(v,vv);a[3]=lca(v,uu);
                sort(a,a+4,cmp); 
                u=a[0],v=a[1];
            }
        }
    }
    printf("u=%d v=%d\n",u,v);
    if(!f) puts("0"); else printf("%d\n",max(0,dis(u,v)-1));
    return 0;
}