#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,ans;
vector<int> row[MAXN];
int p[MAXN],parity[MAXN];
bool odd[MAXN];
vector<int> has[MAXN];
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        has[i].push_back(i);
        odd[i]=false;
        parity[i]=0;
    }
}
int find(int x)
{
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
void unite(int x,int y)
{
    bool ret=false;
    int par=parity[x]^parity[y];
    x=find(x); y=find(y);
    if(x==y) return;
    if((int)has[x].size()<(int)has[y].size()) swap(x,y);
    p[y]=x;
    par=!par;
    odd[x]|=odd[y];
    for(auto u:has[y]) parity[u]^=par;
    has[x].insert(has[x].end(),has[y].begin(),has[y].end());
    has[y].clear();
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<2*m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        row[y].push_back(x);
    }
    init(n);
    for(int i=1;i<=m;i++)
    {
        int u=row[i][0],v=row[i][1];
        if(same(u,v))
        {
            if(!odd[find(u)])
            {
                if(parity[u]==parity[v])
                {
                    odd[find(u)]=true;
                    ans++;
                }
            }
        }
        else
        {
            if((!odd[find(u)])||(!odd[find(v)])) ans++;
            unite(u,v);
        }
    }
    printf("%d\n",ans);
    return 0;
}
