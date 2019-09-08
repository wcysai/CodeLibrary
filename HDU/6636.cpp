#include<bits/stdc++.h>
#define MAXN 85
#define MAXM 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int c[MAXN],k[MAXN],color[MAXM],u[MAXM],v[MAXM],w[MAXM];
ll val[MAXM];
int T,n,m,tot,tot2;
struct LinearMatroid
{
    ll basis[62];
    void clear()
    {
        memset(basis,0,sizeof(basis));
    }
    void add(ll x)
    {
        for(int j=60;j>=0;j--)
        {
            if(!(x&(1LL<<j))) continue;
            if(!basis[j])
            {
                basis[j]=x;
                return;
            }
            else x^=basis[j];
        }
    }
    bool test(ll x)
    {
        for(int j=60;j>=0;j--)
        {
            if(!(x&(1LL<<j))) continue;
            if(!basis[j]) return true; else x^=basis[j];
        }
        return false;
    }
};
struct ColorfulMatroid
{
    int cnt[125];
    void clear()
    {
        memset(cnt,0,sizeof(cnt));
    }
    void add(int x)
    {
        cnt[x]++;
    }
    bool test(int x)
    {
        return (cnt[x]==0);
    }
};

struct GraphMatroid
{
    vector<int> G[MAXN];
    bool vis[MAXN];
    void dfs(int v)
    {
        vis[v]=true;
        for(auto to:G[v]) if(!vis[to]) dfs(to);
    }
    bool test(vector<int> &vec)
    {
        for(int i=1;i<=n+1;i++) G[i].clear();
        memset(vis,false,sizeof(vis));
        for(auto x:vec)
        {
            G[u[x]].push_back(v[x]);
            G[v[x]].push_back(u[x]);
        }
        dfs(1);
        int cnt=0;
        for(int i=1;i<=n+1;i++) cnt+=(vis[i]?1:0);
        return (cnt==n+1);
    }
};

struct PartitionMatroid
{
    int cnt[125];
    bool test(vector<int> &vec)
    {
        memset(cnt,0,sizeof(vec));
        for(auto x:vec) cnt[color[x]]++;
        for(int i=1;i<=m;i++) if(cnt[i]>c[i]-k[i]) return false;
        return true;
    }
};


template <typename MT1, typename MT2>
struct MatroidIntersection
{
    int n;
    MatroidIntersection(int _n):n(_n){}
    int pre[MAXM],id[MAXM],d[MAXM];
    bool inque[MAXM],sink[MAXM],has[MAXM];
    queue<int> que;
    void clear_all()
    {
        memset(inque,false,sizeof(inque));
        memset(sink,false,sizeof(sink));
        memset(pre,0,sizeof(pre));
        for(int i=1;i<=n+1;i++) d[i]=-INF;
        while(que.size()) que.pop();
    }
    vector<int> getcur()
    {
        vector<int> ret;
        for(int i=1;i<=n;i++) if(has[i]) ret.push_back(i);
        return ret;
    }
    void enqueue(int v,int p)
    {
        pre[v]=p;
        if(!inque[v])
        {
            inque[v]=true;
            que.push(v);
        }
    }
    vector<int> run()
    {
        MT1 mt1;  MT2 mt2;
        memset(has,false,sizeof(has));
        while(true)
        {
            vector<int> cur=getcur();
            clear_all();
            for(int i=1;i<=n;i++)
            {
                if(has[i]) continue;
                vector<int> tmp=cur; tmp.push_back(i);
                if(mt1.test(tmp)) {que.push(i); inque[i]=true; d[i]=w[i];}
            }
            for(int i=1;i<=n;i++)
            {
                if(has[i]) continue;
                vector<int> tmp=cur; tmp.push_back(i);
                if(mt2.test(tmp)) sink[i]=true;
            }
            while(que.size())
            {
                int u=que.front(); que.pop();
                if(sink[u])
                {
                    if(d[u]>d[n+1])
                    {
                        d[n+1]=d[u];
                        pre[n+1]=u;
                    }
                }
                for(int i=1;i<=n;i++)
                {
                    if(has[i]==has[u]) continue;
                    has[u]^=1; has[i]^=1;
                    vector<int> tmp=getcur();
                    if(!has[u]) { if(d[u]+w[i]>d[i]&&mt1.test(tmp)) enqueue(i,u); }
                    else {if(d[u]-w[i]>d[i]&&mt2.test(tmp)) enqueue(i,u);}
                    has[u]^=1; has[i]^=1;
                }
            }
            if(!pre[n+1]) return cur;
            int last=pre[n+1];
            while(last)
            {
                has[last]^=1;
                last=pre[last];
            }
        }
    }
};
//Pick Your Own Nim
//In real cases, Linear Matroid Need Optimization to Pass
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        tot=0;
        scanf("%d%d",&n,&m);
        int sum=0;
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&c[i],&k[i]);
            sum+=c[i]-k[i];
            for(int j=1;j<=c[i];j++)
            {
                int l,r,cost;
                scanf("%d%d%d",&l,&r,&cost);
                color[++tot]=i; u[tot]=l; v[tot]=r+1; w[tot]=cost;
            }
        }
        MatroidIntersection<GraphMatroid,PartitionMatroid> matint(tot);
        vector<int> res=matint.run();
        if((int)res.size()!=sum) puts("-1");
    }
    return 0;
}

