#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 205
#define MAXM 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,a[MAXN];
struct edge{int to,del,rev,id;};
int u[MAXM],v[MAXM];
bool vis[MAXN];
vector<edge> G[MAXN];
void add_edge(int u,int v,int id)
{
    G[u].push_back((edge){v,0,(int)G[v].size(),id});
    G[v].push_back((edge){u,0,(int)G[u].size()-1,id});
}
vector<P> ans;
void hierholzer(int v)
{
    vis[v]=true;
    for(auto &e:G[v])
    {
        if(e.del) continue;
        e.del=1; G[e.to][e.rev].del=1;
        if(e.id) ans.push_back(P(v,e.to));
        hierholzer(e.to);
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&u[i],&v[i]);
            add_edge(u[i],v[i],i+1);
        }
        vector<int> odeg;
        for(int i=1;i<=n;i++) if((int)G[i].size()&1) odeg.push_back(i);
        for(int i=0;i<(int)odeg.size();i+=2) add_edge(odeg[i],odeg[i+1],0);
        memset(vis,false,sizeof(vis));
        ans.clear();
        for(int i=1;i<=n;i++) if(!vis[i]) hierholzer(i);
        printf("%d\n",n-(int)odeg.size());
        for(auto p:ans) printf("%d %d\n",p.F,p.S);
    }
    return 0;
}

