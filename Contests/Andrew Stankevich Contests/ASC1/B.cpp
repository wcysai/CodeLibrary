#include<bits/stdc++.h>
#define MAXN 20005
#define MAXM 1000005
#define INF 1000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge {ll to,cap,rev,id;};
ll n,m,S,T;
vector<edge> G[MAXN];
ll level[MAXN];
ll iter[MAXN];
ll u[MAXM],v[MAXM],l[MAXM],r[MAXM],ans[MAXM],w[MAXN];
void add_edge(ll from,ll to,ll cap,ll id)
{
    G[from].push_back((edge){to,cap,(int)G[to].size(),id});
    G[to].push_back((edge){from,0,(int)G[from].size()-1,0});
}
void bfs(ll s)
{
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty())
    {
        ll v=que.front(); que.pop();
        for(ll i=0;i<(int)G[v].size();i++)
        {
            edge &e=G[v][i];
            if(e.cap>0&&level[e.to]<0)
            {
                level[e.to]=level[v]+1;
                que.push(e.to);
            }
        }
    }
}

ll dfs(ll v,ll t,ll f)
{
    if(v==t) return f;
    for(ll &i=iter[v];i<(int)G[v].size();i++)
    {
        edge &e=G[v][i];
        if(level[v]<level[e.to]&&e.cap>0)
        {
            ll d=dfs(e.to,t,min(f,e.cap));
            if(d>0)
            {
                e.cap-=d;
                G[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}


ll max_flow(ll s,ll t)
{
    ll flow=0;
    for(;;)
    {
        bfs(s);
        if(level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        ll f;
        while((f=dfs(s,t,INF))>0) flow+=f;
    }
}

int main()
{
    freopen("cooling.in","r",stdin);
    freopen("cooling.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    S=n+1,T=n+2;
    ll sum=0;
    for(ll i=1;i<=m;i++)
    {
        scanf("%lld%lld%lld%lld",&u[i],&v[i],&l[i],&r[i]);
        w[u[i]]+=l[i]; w[v[i]]-=l[i];
        add_edge(u[i],v[i],r[i]-l[i],i); 
    }
    for(ll i=1;i<=n;i++)
    {
        if(w[i]>0) {add_edge(i,T,w[i],0); sum+=w[i];}
        else add_edge(S,i,-w[i],0);
    }
    ll f=max_flow(S,T);
    if(f!=sum) {puts("NO"); return 0;}
    puts("YES");
    for(ll i=1;i<=n+2;i++)
    {
        for(auto &e:G[i])
        {
            if(!e.id) continue;
            ans[e.id]=l[e.id]+(r[e.id]-l[e.id]-e.cap);
        }
    }
    for(ll i=1;i<=m;i++) printf("%lld\n",ans[i]);
    //add_edge(S,s,INF); add_edge(s,S,INF);
}
