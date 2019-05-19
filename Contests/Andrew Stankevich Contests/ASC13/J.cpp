#include<bits/stdc++.h>
#define MAXN 50005
#define MAXM 50005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,V,tot;
struct edge {int to,id;};
vector<edge> G[MAXN];
vector<int> GG[MAXN];
int match[MAXN];
bool used[MAXN];
map<string,int> mp;
string str;
int ideg[MAXN],odeg[MAXN];
int from[MAXN],u[MAXN],v[MAXN];
int uu[MAXN],vv[MAXN];
int ans[MAXN];
map<P,int> edges;
int get_id(string str)
{
    while((int)str.size()>0&&str[0]==' ') str=str.substr(1);
    while((int)str.size()>0&&str.back()==' ') str.pop_back();
    if(mp.find(str)==mp.end()) mp[str]=++tot;
    return mp[str];
}
pair<int,int> parse_input()
{
    getline(cin,str);
    for(int i=0;i<(int)str.size();i++)
    {
        if(str[i]==',')
        {
            string s=str.substr(0,i);
            string t=str.substr(i+1);
            return make_pair(get_id(s),get_id(t));
        }
    }
    return P(0,0);
}
void add_edge(int u,int v)
{
    GG[u].push_back(v);
    GG[v].push_back(u);
}
bool dfs(int v)
{
    used[v]=true;
    for(int i=0;i<(int)GG[v].size();i++)
    {
        int u=GG[v][i],w=match[u];
        if(w<0||(!used[w]&&dfs(w)))
        {
            match[v]=u;
            match[u]=v;
            return true;
        }
    }
    return false;
}
int bipartite_matching()
{
    int res=0;
    memset(match,-1,sizeof(match));
    for(int v=0;v<V;v++)
    {
        if(match[v]<0)
        {
            memset(used,0,sizeof(used));
            if(dfs(v)) res++;
        }
    }
    return res;
}
int main()
{
    freopen("tickets.in","r",stdin);
    freopen("tickets.out","w",stdout);
    scanf("%d%d ",&n,&m);
    bool f=true;
    for(int i=0;i<n;i++)
    {
        P p=parse_input();
        ideg[p.S]++; odeg[p.F]++;
        if(ideg[p.S]>1) f=false;
        if(odeg[p.F]>1) f=false;
        u[i]=p.F,v[i]=p.S;
        from[p.S]=i;
    }
    for(int i=1;i<=m;i++)
    {
        P p=parse_input();
        uu[i]=p.F,vv[i]=p.S;
        G[p.F].push_back((edge){p.S,i});
        G[p.S].push_back((edge){p.F,i});
        edges[p]=i; edges[P(p.S,p.F)]=i;
    }
    if(!f)
    {
        puts("NO");
        return 0;
    }
    int sz=(int)mp.size();
    for(int i=1;i<=sz;i++)
    {
        for(auto e:G[i])
        {
            int to=e.to;
            if(ideg[to]==0) continue;
            if(i==u[from[to]])
            {
                int vt=min(i,to);
                add_edge(from[to],vt+n-1);
            }
            if(ideg[i]==0&&odeg[i]==0&&edges.count(P(u[from[to]],i)))
            {
                add_edge(from[to],i+n-1);
            }
        }
    }
    V=n+sz;
    if(bipartite_matching()<n) {puts("NO"); return 0;}
    puts("YES");
    for(int i=0;i<n;i++)
    {
        int id=match[i]-n+1;
        if(u[i]==id) swap(u[i],v[i]);
        if(v[i]==id) printf("%d %d\n",1,edges[P(u[i],v[i])]);
        else printf("%d %d %d\n",2,edges[P(u[i],id)],edges[P(id,v[i])]);
    }
    return 0;
}
