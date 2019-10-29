#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,x[MAXN],y[MAXN],lastid,lastv;
vector<int> dis;
struct edge
{
    int to,id;
};
vector<edge> G[MAXN];
void add_edge(int u,int v,int id)
{
    G[u].push_back((edge){v,id});
    G[v].push_back((edge){u,id});
}
struct node
{
    int id,u,v;
};
vector<node> ans;
bool vis[MAXN];
void dfs(int v)
{
    vis[v]=true;
    for(auto e:G[v])
    {
        int to=e.to,id=e.id;
        if(vis[to]) continue;
        lastid=id; lastv=to;
        dfs(to);
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        dis.clear(); ans.clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
            dis.push_back(x[i]); dis.push_back(y[i]);
        }
        sort(dis.begin(),dis.end()); dis.erase(unique(dis.begin(),dis.end()),dis.end());
        for(int i=1;i<=2*n;i++) G[i].clear();
        for(int i=1;i<=n;i++)
        {
            x[i]=lower_bound(dis.begin(),dis.end(),x[i])-dis.begin()+1;
            y[i]=lower_bound(dis.begin(),dis.end(),y[i])-dis.begin()+1;
            add_edge(x[i],y[i],i);
        }
        int sz=(int)dis.size();
        for(int i=1;i<=sz;i++) vis[i]=false;
        lastid=-1; lastv=-1;
        for(int i=1;i<=sz;i++)
        {
            if(!vis[i])
            {
                if(lastid!=-1)
                {
                    ans.push_back((node){lastid,lastv,i});
                }
                dfs(i);
            }
        }
        printf("%d\n",(int)ans.size());
        for(auto p:ans) printf("%d %d %d\n",p.id,dis[p.u-1],dis[p.v-1]);
    }
    return 0;
}
