#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,m,q;
int bigid[MAXN],deg[MAXN];
int a[MAXN];
vector<int> G[MAXN],bG[MAXN];
struct segtree
{
    int cnt[4*MAXN];
    bool full[4*MAXN];
    void build(int k,int l,int r)
    {
        cnt[k]=0; full[k]=false;
        if(l==r) return;
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
    }
    void pushup(int k)
    {
        cnt[k]=cnt[k*2]+cnt[k*2+1];
        full[k]=(full[k*2]&&full[k*2+1]);
    }
    void update(int k,int l,int r,int p,int v)
    {
        if(l==r)
        {
            cnt[k]+=v;
            full[k]=(cnt[k]>0?true:false);
            return;
        }
        int mid=(l+r)/2;
        if(p<=mid) update(k*2,l,mid,p,v); else update(k*2+1,mid+1,r,p,v);
        pushup(k);
    }
    int query(int k,int l,int r)
    {
        if(l==r) return l;
        int mid=(l+r)/2;
        if(!full[k*2]) return query(k*2,l,mid); else return query(k*2+1,mid+1,r);
    }
}seg[505];
bool pool[505];
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<=n;i++) bG[i].clear();
        for(int i=1;i<=n;i++) bigid[i]=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v); G[v].push_back(u);
        }
        int tot=0;
        for(int i=1;i<=n;i++) if(G[i].size()>=2000) {bigid[i]=++tot; deg[tot]=(int)G[i].size();}
        for(int i=1;i<=tot;i++) seg[i].build(1,1,deg[i]+1);
        for(int i=1;i<=n;i++)
        {
            for(auto to:G[i])
            {
                if(bigid[to]) 
                {
                    int id=bigid[to];
                    bG[i].push_back(id);
                    if(a[i]<deg[id]) seg[id].update(1,1,deg[id]+1,a[i]+1,1);
                }
            }
        }
        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            int type,u,x;
            scanf("%d",&type);
            if(type==1)
            {
                scanf("%d%d",&u,&x);
                for(auto to:bG[u])
                {
                    if(a[u]<deg[to]) seg[to].update(1,1,deg[to]+1,a[u]+1,-1);
                    if(x<deg[to]) seg[to].update(1,1,deg[to]+1,x+1,1);
                }
                a[u]=x;
            }
            else
            {
                scanf("%d",&u);
                if(!bigid[u])
                {
                    int d=(int)G[u].size();
                    for(int i=0;i<=d;i++) pool[i]=false;
                    for(auto to:G[u]) if(a[to]<d) pool[a[to]]=true;
                    int ans=0;
                    while(pool[ans]) ans++;
                    printf("%d\n",ans);
                }
                else
                {
                    int id=bigid[u];
                    printf("%d\n",seg[id].query(1,1,deg[id]+1)-1);
                }
                
            }
            
        }
    }
}