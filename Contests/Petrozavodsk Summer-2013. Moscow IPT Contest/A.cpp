#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,cnt;
vector<int> G[MAXN];
int color[MAXN],d[MAXN];
int maxi=0;
int id[MAXN];
int label[MAXN];
set<int> reach[MAXN];
void dfs(int v,int p,int c)
{
    color[v]=c;
    for(auto to:G[v])
    {
        if(to==p) continue;
        if(color[to]==-1) dfs(to,v,c^1);
    }
}
bool les(const vector<int> &a,const vector<int> &b)
{
    if(a.size()!=b.size()) return a.size()<b.size();
    for(int i=0;i<(int)a.size();i++) if(a[i]!=b[i]) return a[i]<b[i];
    return false;
}
bool same(const vector<int> &a,const vector<int> &b)
{
    if(a.size()!=b.size()) return false;
    for(int i=0;i<(int)a.size();i++) if(a[i]!=b[i]) return false;
    return true;
}
bool cmp(int x,int y)
{
    return les(G[x],G[y]);
}
void bfs(int v,int dis)
{
    d[v]=dis;
    cnt++;
    queue<int> que; que.push(v);
    while(que.size())
    {
        int u=que.front(); que.pop();
        for(auto to:reach[u])
        {
            if(d[to]==-1)
            {
                d[to]=d[u]+1;
                cnt++;
                maxi=max(d[to],maxi);
                que.push(to);
            }
        }
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
    }
    memset(color,-1,sizeof(color));
    for(int i=1;i<=n;i++) if(color[i]==-1) dfs(i,0,0);
    bool f=true;
    for(int i=1;i<=n;i++)
        for(auto to:G[i])
            if(color[to]==color[i]) f=false;
    if(!f) puts("NET");
    else
    {
        for(int i=1;i<=n;i++) id[i]=i;
        for(int i=1;i<=n;i++) sort(G[i].begin(),G[i].end());
        sort(id+1,id+n+1,cmp);
        label[id[1]]=1;
        for(int i=2;i<=n;i++) if(same(G[id[i]],G[id[i-1]])) label[id[i]]=label[id[i-1]]; else label[id[i]]=label[id[i-1]]+1;
        int tot=label[id[n]];
        for(int i=1;i<=n;i++)
            for(auto to:G[i])
                reach[label[i]].insert(label[to]);
        for(int i=1;i<=n;i++)
        {
            if(reach[i].size()>=3)
            {
                puts("NET");
                return 0;
            }
        }
        memset(d,-1,sizeof(d));
        maxi=1; cnt=0;
        for(int i=1;i<=tot;i++)
        {
            if(d[i]==-1&&((int)reach[i].size()==1||(int)reach[i].size()==0))
            {
               bfs(i,maxi);
               maxi+=2;
            }
        }
        if(cnt!=tot) puts("NET");
        else
        {
            puts("DA");
            for(int i=1;i<=n;i++) printf("%d%c",d[label[i]],i==n?'\n':' ');
        }
    }
    return 0;
}
