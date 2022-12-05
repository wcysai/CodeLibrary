#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,m,p[MAXN],pos[MAXN];
vector<int> G[MAXN];
int deg[MAXN];
vector<int> order;
bool vis[MAXN];
int mini[MAXN];
void dfs(int v)
{
    vis[v]=true;
    for(auto to:G[v])
        if(!vis[to]) dfs(to);
    order.push_back(v);
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) pos[i]=deg[i]=0;
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&p[i]);
            if(p[i]) pos[p[i]]=i;
        }
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v); deg[v]++;
        }
        for(int i=1;i<=n;i++) vis[i]=false;
        order.clear();
        for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
        reverse(order.begin(),order.end());
        bool f=true;
        for(int i=(int)order.size()-1;i>=0;i--)
        {
            int v=order[i];
            mini[v]=n+1; if(p[v]) mini[v]=p[v];
            for(auto to:G[v]) mini[v]=min(mini[v],mini[to]);
            if(p[v]&&(mini[v]!=p[v])) f=false;
            //printf("v=%d mini=%d\n",v,mini[v]);
        }
        if(!f) {puts("-1"); continue;}
        priority_queue<P,vector<P>,greater<P> > pque;
        for(int i=1;i<=n;i++) if((!deg[i])&&(!p[i])) pque.push(P(mini[i],i));
        for(int tot=1;tot<=n;tot++)
        {
            if(pos[tot])
            {
                if(deg[pos[tot]]) {f=false; break;}
                for(auto to:G[pos[tot]])
                {
                    deg[to]--;
                    if(deg[to]==0&&p[to]==0) pque.push(P(mini[to],to));
                }
            }
            else
            {
                if(!pque.size()) {f=false; break;}
                P q=pque.top(); pque.pop();
                int minval=q.F,v=q.S;
                if(tot>minval) {f=false; break;}
                pos[tot]=v; p[v]=tot;
                for(auto to:G[v])
                {
                    deg[to]--;
                    if(deg[to]==0&&p[to]==0) pque.push(P(mini[to],to));
                }
            }
        }
        if(!f) {puts("-1"); continue;}
        for(int i=1;i<=n;i++) printf("%d%c",p[i],i==n?'\n':' ');
    }
    return 0;
}

