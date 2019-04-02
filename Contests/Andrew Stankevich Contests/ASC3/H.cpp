#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,b,st[MAXN],t,tot,id[MAXN],cap[MAXN];
vector<int> G[MAXN];
void dfs(int v,int p)
{
    int now=t;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int to=G[v][i];
        if(to==p) continue;
        dfs(to,v);
        if(t-now>=b)
        {
            cap[++tot]=v;
            while(t>now) id[st[t--]]=tot;
        }
    }
    st[++t]=v;
}
int main()
{
    freopen("royal.in","r",stdin);
    freopen("royal.out","w",stdout);
    scanf("%d%d",&n,&b);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(v);G[v].push_back(u);
    }
    if(n==b)
    {
        printf("1\n");
        for(int i=1;i<=n;i++) printf("%d%c",1,i==n?'\n':' ');
        printf("1\n");
        return 0;
    }
    tot=0;t=0;
    dfs(1,0);
    while(t) id[st[t--]]=tot;
    printf("%d\n",tot);
    for(int i=1;i<=n;i++)
        printf("%d%c",id[i],i==n?'\n':' ');
    for(int i=1;i<=tot;i++)
        printf("%d%c",cap[i],i==tot?'\n':' ');
    return 0;
}
