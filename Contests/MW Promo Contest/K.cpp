#include<bits/stdc++.h>
#define MAXN 10005
#define MAXM 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,p;
bool vis[MAXN];
vector<P> G[MAXN];
set<int> s[MAXN];
void add_edge(int u,int v,int id)
{
    G[u].push_back(P(v,id));
    G[v].push_back(P(u,id));
}
int main()
{
    memset(vis,false,sizeof(vis));
    scanf("%d%d%d",&n,&m,&p);
    queue<int> que;
    for(int i=1;i<=p;i++)
    {
        int x;
        scanf("%d",&x);
        que.push(x); vis[x]=true;
    }
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v,i);
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++)
        {
            int x;
            scanf("%d",&x);
            s[i].insert(x);
        }
    }
    while(que.size())
    {
        int v=que.front(); que.pop();
        for(auto e:G[v])
        {
            int to=e.F,id=e.S;
            if(vis[to]) continue;
            if(!s[to].count(id))
            {
                vis[to]=true;
                que.push(to);
            }
        }
    }
    int id=-1;
    for(int i=1;i<=n;i++) if(!vis[i]) {id=i; break;}
    if(id==-1) puts("Impossible"); else printf("%d\n",id);
    return 0;
}