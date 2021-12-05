#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,p[MAXN],r[MAXN];
P q[MAXN];
int a[MAXN],dep[MAXN];
vector<int> G[MAXN];
vector<int> T[MAXN];
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
void dfs(int v)
{
    for(auto to:T[v])
    {
        dep[to]=dep[v]+1;
        dfs(to);
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) G[i].clear(),T[i].clear();
        init(n);
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v); G[v].push_back(u);
        }
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            q[i].F=a[i]; q[i].S=i;
        }
        sort(q+1,q+n+1);
        for(int i=1;i<=n;i++)
        {
            int v=q[i].S;
            for(auto to:G[v])
            {
                if(a[to]<a[v]) 
                {
                    T[v].push_back(find(to));
                    p[find(to)]=v;
                }
            }
        }
        dep[q[n].S]=1;
        dfs(q[n].S);
        for(int i=1;i<=n;i++) printf("%d\n",dep[i]);
    }
    return 0;
}
