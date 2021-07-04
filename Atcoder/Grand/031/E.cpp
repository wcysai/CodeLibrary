#include<bits/stdc++.h>
#define MAXN 85
#define MAXM 325
#define MAXV 1000
#define INF 1000000000
#define INFL 1000000000000000LL
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
struct edge{int to,cap; ll cost; int rev;};
ll dist[MAXV],h[MAXV];
int prevv[MAXV],preve[MAXV];
int n,m,V;
vector<edge> G[MAXV];
int xl[MAXN],xr[MAXN],yl[MAXN],yr[MAXN];
int type[MAXM],a[MAXM],b[MAXM];
int x[MAXN],y[MAXN];
ll v[MAXN];
void add_edge(int from,int to,int cap,ll cost)
{
    G[from].push_back((edge){to,cap,cost,(int)G[to].size()});
    G[to].push_back((edge){from,0,-cost,(int)G[from].size()-1});
}
ll min_cost_flow(int s,int t,int f)
{
    ll res=0;
    fill(h+1,h+V+1,0);
    while(f>0)
    {
        priority_queue<P,vector<P>,greater<P> >que;
        fill(dist+1,dist+V+1,1000000000000000000LL);
        dist[s]=0;
        que.push(P(0,s));
        while(!que.empty())
        {
            P p=que.top(); que.pop();
            int v=p.second;
            if(dist[v]<p.first) continue;
            for(int i=0;i<G[v].size();i++)
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
        if(dist[t]==1000000000000000000LL)
        {
            return -1;
        }
        for(int v=1;v<=V;v++) h[v]+=dist[v];
        int d=f;
        for(int v=t;v!=s;v=prevv[v])
        {
            d=min(d,G[prevv[v]][preve[v]].cap);
        }
        f-=d;
        res+=d*h[t];
        for(int v=t;v!=s;v=prevv[v])
        {
            edge &e=G[prevv[v]][preve[v]];
            e.cap-=d;
            G[v][e.rev].cap+=d;
        }
    }
    return res;
}
string str;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d%lld",&x[i],&y[i],&v[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        cin>>str;
        if(str[0]=='L') type[i]=0;
        else if(str[0]=='R') type[i]=1;
        else if(str[0]=='D') type[i]=2;
        else type[i]=3;
        scanf("%d%d",&a[i],&b[i]);
    }
    ll ans=0;
    for(int i=1;i<=n;i++)//enumerate on the number of jewels chosen
    {
        for(int j=1;j<=i;j++) xl[j]=yl[j]=-INF,xr[j]=yr[j]=INF;
        for(int j=1;j<=m;j++)
        {
            if(b[j]>=i) continue;
            if(type[j]==0) xl[b[j]+1]=a[j]+1;
            else if(type[j]==1) xr[i-b[j]]=a[j]-1;
            else if(type[j]==2) yl[b[j]+1]=a[j]+1;
            else if(type[j]==3) yr[i-b[j]]=a[j]-1;
        }
        for(int j=2;j<=i;j++) xl[j]=max(xl[j],xl[j-1]),yl[j]=max(yl[j],yl[j-1]);
        for(int j=i-1;j>=1;j--) xr[j]=min(xr[j],xr[j+1]),yr[j]=min(yr[j],yr[j+1]);
        V=2*i+2*n+2;
        int s=V-1,t=V;
        for(int j=1;j<=V;j++) G[j].clear();
        for(int j=1;j<=i;j++) add_edge(s,j,1,0);
        for(int j=i+1;j<=2*i;j++) add_edge(j,t,1,0);
        for(int j=1;j<=n;j++) add_edge(2*i+j,2*i+n+j,1,0);
        for(int j=1;j<=i;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(x[k]>=xl[j]&&x[k]<=xr[j]) add_edge(j,2*i+k,1,INFL-v[k]);
                if(y[k]>=yl[j]&&y[k]<=yr[j]) add_edge(2*i+n+k,i+j,1,0);
            }
        }
        ll res=min_cost_flow(s,t,i);
        if(res!=-1) ans=max(ans,INFL*i-res);
    }
    printf("%lld\n",ans);
    return 0;
}
