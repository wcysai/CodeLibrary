#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/priority_queue.hpp>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int,int> P;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef __gnu_pbds::priority_queue<int,greater<int>,pairing_heap_tag> pq;
int n,k,x,y,ans[MAXN];
int cnt[MAXN],deg[MAXN],color[MAXN],save[MAXN];
char str[2];
map<P,int> mp;
vector<int> G[MAXN];
bool vis[MAXN];
struct edges
{
    int l,r,u,v;
};
vector<edges> E;
void add_edge(int l,int r,int u,int v)
{
    E.push_back((edges){l,r,u,v});
}
void ADD_EDGE(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
void dfs(int v,int c)
{
    vis[v]=true; color[v]=c;
    for(auto to:G[v]) if(!vis[to]) dfs(to,c);
}
void solve(int l,int r,vector<edges> &E,int vn,int add_vn)
{
    //printf("%d %d %d %d\n",l,r,vn,add_vn);
    if(cnt[l-1]==cnt[r]) return;
    if(!E.size())
    {
        for(int i=l;i<=r;i++) ans[i]=vn+add_vn;
        return;
    }
    vector<edges> E1;
    for(int i=1;i<=vn;i++) G[i].clear();
    for(int i=0;i<(int)E.size();i++)
    {
        if(E[i].u!=E[i].v)
        {
            if(E[i].l<=l&&E[i].r>=r) ADD_EDGE(E[i].u,E[i].v);
            else if(E[i].l>r||E[i].r<l) continue;
            else E1.push_back(E[i]);
        }
    }
    int tot=0;
    for(int i=1;i<=vn;i++) vis[i]=false;
    for(int i=1;i<=vn;i++)
    {
        if(!vis[i])
        {
            tot++;deg[tot]=0;
            dfs(i,tot);
        }
    }
    for(int i=0;i<(int)E1.size();i++)
    {
        E1[i].u=color[E1[i].u];
        E1[i].v=color[E1[i].v];
        if(E1[i].u!=E1[i].v) 
        {
            deg[E1[i].u]++;
            deg[E1[i].v]++;
        }
    }
    int vn1=0;
    for(int i=1;i<=tot;i++) 
    {
        if(deg[i]>0) vn1++;
        save[i]=vn1;
        add_vn+=!deg[i];
    }
    for(int i=0;i<(int)E1.size();i++)
    {
        E1[i].u=save[E1[i].u];
        E1[i].v=save[E1[i].v];
    }
    int mid=(l+r)/2;
    solve(l,mid,E1,vn1,add_vn);
    solve(mid+1,r,E1,vn1,add_vn);
}
int main()
{
    freopen("connect.in","r",stdin);
    freopen("connect.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=k;i++)
    {
        scanf("%s",str);
        if(str[0]=='?')
        {
            cnt[i]=cnt[i-1]+1;
            continue;
        }
        scanf("%d%d",&x,&y);
        if(x>y) swap(x,y);
        if(str[0]=='+') mp[P(x,y)]=i;
        else
        {
            add_edge(mp[P(x,y)],i-1,x,y);
            mp[P(x,y)]=-1;
        }
        cnt[i]=cnt[i-1];
    }
    for(auto p:mp) if(p.S!=-1) add_edge(p.S,k,p.F.F,p.F.S);
    solve(1,k,E,n,0);
    for(int i=1;i<=k;i++) if(cnt[i]!=cnt[i-1]) printf("%d\n",ans[i]);
    return 0;
}
