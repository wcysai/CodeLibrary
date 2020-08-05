#include<bits/stdc++.h>
#define MAXN 55
#define MAXM 105
#define MAXQ 1000005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
struct edge{int to,cap,cost,rev;};
int dist[MAXN],h[MAXN],prevv[MAXN],preve[MAXN];
int n,m,q,x,y,cur;
vector<edge> G[MAXN];
bool save[MAXM];
ll num,denom,res;
void add_edge(int from,int to,int cap,int cost)
{
    G[from].push_back((edge){to,cap,cost,(int)G[to].size()});
    G[to].push_back((edge){from,0,-cost,(int)G[from].size()-1});
}
int min_cost_flow(int s,int t,P p)
{
    while(1LL*cur*p.S<p.F)
    {
        if(!save[cur])
        {
             priority_queue<P,vector<P>,greater<P> >que;
            fill(dist+1,dist+n+1,INF);
            dist[s]=0;
            que.push(P(0,s));
            while(!que.empty())
            {
                P p=que.top(); que.pop();
                int v=p.second;
                if(dist[v]<p.first) continue;
                for(int i=0;i<(int)G[v].size();i++)
                {
                    edge &e=G[v][i];
                    if(e.cap>0&&dist[e.to]>dist[v]+e.cost+h[v]-h[e.to])
                    {
                        dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
                        prevv[e.to]=v;
                        preve[e.to]=i;
                        que.push(P(dist[e.to],e.to));
                    }
                }
            }
            if(dist[t]==INF)
            {
                return -1;
            }  
            for(int v=1;v<=n;v++) h[v]+=dist[v];
            save[cur]=true;
        }
        if(1LL*(cur+1)*p.S>=p.F)
        {
            denom=p.F;
            num=p.F-1LL*cur*p.S;
            num=num*h[t];
            num+=res*p.S;
            ll g=__gcd(num,denom);
            num/=g; denom/=g;
            return 0;
        }
        res+=h[t];
        cur++;
        for(int v=t;v!=s;v=prevv[v])
        {
            edge &e=G[prevv[v]][preve[v]];
            e.cap--;
            G[v][e.rev].cap++;
        }
    }
    return res;
}
struct node
{
    int x,y,id;
};
bool cmp(node u,node v)
{
    return 1LL*u.x*v.y<1LL*v.x*u.y;
}
vector<node> v;
pair<ll,ll> ans[MAXQ];
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        v.clear(); cur=0; res=0;
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u,v,1,w);
        }
        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            v.push_back((node){y,x,i});
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<q;i++) ans[i]=P(-1,-1);
        memset(save,false,sizeof(save));
        for(int i=0;i<q;i++)
        {
            int ret=min_cost_flow(1,n,P(v[i].x,v[i].y));
            if(ret==-1) break;
            else ans[v[i].id]=make_pair(num,denom);
        }
        for(int i=0;i<q;i++)
        {
            if(ans[i].F==-1) puts("NaN");
            else printf("%lld/%lld\n",ans[i].F,ans[i].S);
        }
    }
    return 0;
}
