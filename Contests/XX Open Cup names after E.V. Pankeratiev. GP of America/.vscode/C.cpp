#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,q;
int x[MAXN],y[MAXN],r[MAXN];
int cnt[MAXN],fa[MAXN];
int root[MAXN],f[MAXN][2],g[MAXN][2];
bool same[MAXN];
//f: any
//g: can't choose
vector<int> order;
vector<int> G[MAXN];
bool vis[MAXN];
double linenow;
struct node
{
    int id;
    bool up;
    node(){}
    node(int id,bool up)
    {
        this->id=id;
        this->up=up;
    }
    double gety()const
    {
        return y[id]+sqrt(pow(r[id],2)-pow(x[id]-linenow,2))*(up?1:-1);
    }
    bool operator <(const node a)const
    {
        double ay=gety(),by=a.gety();
        return ay!=by?ay>by:up>a.up;
    }
};
set<node>st;
set<node>::iterator it,jt;

void add_edge(int u,int v)
{
    u++; v++;
    G[u].push_back(v);
    G[v].push_back(u);
}
bool inside(int i,int j)
{
    int dx=x[i]-x[j],dy=y[i]-y[j];
    return 1LL*dx*dx+1LL*dy*dy<=1LL*r[i]*r[j];
}
void build_forest(int N)
{
    vector<P> events;
    for(int i=0;i<N;i++)
    {
        events.push_back(P(x[i]-r[i],i));
        events.push_back(P(x[i]+r[i],i+N));
    }
    sort(events.begin(),events.end());
    for(int i=0;i<(int)events.size();i++)
    {
        int id=events[i].S%N;
        if(events[i].second>=N)
        {
            st.erase(node(id,0));
            st.erase(node(id,1));
            continue;
        }
        linenow=events[i].F;
        it=jt=st.insert(node(id,1)).F;
        if(it==st.begin()||++jt==st.end())
        {
        	cnt[id]=1;
        	fa[id]=N;
        	add_edge(N,id);
        }
        else
        {
            it--;
            if(it->id==jt->id)
            {
            	cnt[id]=cnt[it->id]+1;
            	fa[id]=it->id;
            	add_edge(it->id,id);
            }
            else
            {
            	cnt[id]=max(cnt[it->id],cnt[jt->id]);
            	if(cnt[it->id]<cnt[jt->id])
            	{
            		fa[id]=it->id;
            		add_edge(it->id,id);
            	}
            	else if(cnt[it->id]>cnt[jt->id])
            	{
            		fa[id]=jt->id;
            		add_edge(jt->id,id);
            	}
            	else
            	{
            		fa[id]=fa[it->id];
            		add_edge(fa[it->id],id);
            	}
			}
        }
        st.insert(node(id,0));
    }

}
void dfs(int v,int p)
{
    vis[v]=true;
    if(v<=n)
    {
        for(auto to:G[v])
        {
            if(to==p) continue;
            dfs(to,v);
            f[v][0]+=g[to][0];
            g[v][0]+=f[to][0];
        }
        f[v][0]=max(f[v][0]+1,g[v][0]);
    }
    else
    {
        for(auto to:G[v])
        {
            if(to==p) continue;
            dfs(to,v);
            f[v][0]+=f[to][0];
            g[v][0]+=g[to][0];
        }
        f[v][1]=g[v][0]; g[v][1]=f[v][0];
        f[v][1]=max(f[v][1]+1,g[v][1]);
    }
}
int main()
{
    scanf("%d%d",&n,&q);
    for(int i=0;i<n+q;i++) scanf("%d%d%d",&x[i],&y[i],&r[i]);
    build_forest(n+q);
    memset(vis,false,sizeof(vis));
    int ans=0;
    dfs(n+q+1,0);
    for(int i=n+1;i<=n+q;i++) printf("%d\n",f[i][1]); 
    return 0;
}