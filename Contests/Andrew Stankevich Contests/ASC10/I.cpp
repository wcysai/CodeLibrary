#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,m,p,s,t;
struct edge{ll to,cap,rev;};
vector<edge> G[MAXN];
ll level[MAXN],iter[MAXN];
map<P,int> mp;
vector<int> ans;
int deg[MAXN];
void add_edge(ll from,ll to,ll cap)
{
    G[from].push_back((edge){to,cap,(int)G[to].size()});
    G[to].push_back((edge){from,0,(int)G[from].size()-1});
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
    freopen("trade.in","r",stdin);
    freopen("trade.out","w",stdout);
    scanf("%lld%lld%lld",&n,&m,&p);
    ll s=n+m+1,t=n+m+2,ss=n+m+3,tt=n+m+4;
    for(ll i=0;i<p;i++)
    {
        ll u,v;
        scanf("%lld%lld",&u,&v);
        if(!mp[P(u,n+v)]) 
        {
            add_edge(u,n+v,1);
            mp[P(u,n+v)]=i+1; 
        }
    }
    for(ll i=1;i<=n;i++)
    { 
        add_edge(s,i,INF);
        add_edge(ss,i,2);
    }
    for(ll i=n+1;i<=n+m;i++)
    {
        add_edge(i,t,INF);
        add_edge(i,tt,2);
    }
    add_edge(ss,t,2*m); add_edge(s,tt,2*n); add_edge(t,s,INF);
    ll f=max_flow(ss,tt);
    if(f!=2*(n+m))
    {
        puts("-1");
        return 0;
    }
    G[ss].clear();G[tt].clear();
    for(ll i=1;i<=n+m+2;i++)
    {
        int now=0;
        while(now<(int)G[i].size())
        {
            if(G[i][now].to==tt||(i==t&&G[i][now].to==s))
            {
                G[i].erase(G[i].begin()+now);
            }
            else now++;
        }
    }
    max_flow(t,s);
    for(ll i=1;i<=n;i++)
        for(auto e:G[i])
            if(e.to>=n+1&&e.to<=n+m&&e.cap==0)
            {
                ans.push_back(mp[P(i,e.to)]);
                deg[i]++; deg[e.to]++;
            }
    for(int i=1;i<=n+m;i++) assert(deg[i]>=2);
    printf("%d\n",(int)ans.size());
    sort(ans.begin(),ans.end());
    for(auto x:ans) printf("%d ",x);
    puts("");
    return 0;
}
