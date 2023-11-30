#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXLOGN 20
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,tot,n,p[MAXN];
vector<int> G[MAXN];
int st[MAXN],ed[MAXN];
int pa[MAXLOGN][MAXN];
int depth[MAXN];
int bit[MAXN+1];
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=n)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
void dfs(int v,int p,int d)
{
    st[v]=++tot;
    pa[0][v]=p;
    depth[v]=d;
    for(int i=0;i<(int)G[v].size();i++)
        if(G[v][i]!=p) dfs(G[v][i],v,d+1);
    ed[v]=tot;
}
bool is_anc(int u,int v){
    return st[u]<=st[v]&&ed[u]>=ed[v];
}
void init(int V)
{
    tot=0;
    dfs(1,-1,0);
    for(int k=0;k+1<MAXLOGN;k++)
    {
        for(int v=1;v<=V;v++)
        {
            if(pa[k][v]<0) pa[k+1][v]=-1;
            else pa[k+1][v]=pa[k][pa[k][v]];
        }
    }
}
int get_sz(int v){
    return sum(ed[v])-sum(st[v]-1);
}
int get(int v,int x)
{
    for(int k=0;k<MAXLOGN;k++)
        if((x>>k)&1)
            v=pa[k][v];
    return v;
};
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=2;i<=n;i++) {
            scanf("%d",&p[i]);
            G[i].push_back(p[i]); G[p[i]].push_back(i);
        }
        init(n);
        for(int i=1;i<=n;i++) bit[i]=0;
        add(st[1],1);
        int cent=1,max_sz=0;
        for(int i=2;i<=n;i++){
            add(st[i],1);
            if(is_anc(cent,i)){
                int u=get(i,depth[i]-depth[cent]-1);
                int sz=get_sz(u);
                if(sz>=(i+1)/2){
                    cent=u;
                    max_sz=i/2;
                }
                else max_sz=max(max_sz,sz);
            }
            else{
                int sz=get_sz(cent);
                if(get_sz(cent)<(i+1)/2){
                    cent=pa[0][cent];
                    max_sz=i/2;
                }
                else max_sz=max(max_sz,i-sz);
            }
            printf("%d ",i-2*max_sz);
        }
        printf("\n");
    }
    return 0;
}

