#include<bits/stdc++.h>
#define MAXN 5005
#define MAXM 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
vector<int> G[MAXN];
int p[MAXN],r[MAXN],ord[MAXN],id[MAXN];
bool destroyed[MAXN];
bool has[MAXN][MAXN];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        r[i]=0;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) p[x]=y;
    else
    {
        p[y]=x;
        if(r[x]==r[y]) r[x]++;
    }
}
int main()
{
    freopen("bombing.in","r",stdin);
    freopen("bombing.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&ord[i]);
        id[ord[i]]=i;
    }
    memset(has,false,sizeof(has));
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v); G[v].push_back(u);
        has[u][v]=has[v][u]=true;
    }
    memset(destroyed,true,sizeof(destroyed));
    init(n);
    for(int i=n;i>=1;i--)
    {
        int v=ord[i];
        if(G[v].size()) 
        {
            int last=n+1,u=-1;
            for(auto to:G[v])
            {
                if(destroyed[to]) continue;
                if(id[to]<last) 
                {
                    last=id[to];
                    u=to;
                }
            }
            for(auto to:G[v])
            {
                if(destroyed[to]) continue;
                if(to==u||to==v) continue;
                if(!has[u][to])
                {
                    puts("NO");
                    return 0;
                }
            }
        }
        destroyed[v]=false;
    }
    puts("YES");
    return 0;
}
