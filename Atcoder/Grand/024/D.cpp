#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int n;
int tot;
vector<int> G[MAXN];
int ans[2*MAXN],maxd;
void add_edge(int u,int v)
{
    tot++;
    G[n+tot].push_back(u); G[u].push_back(n+tot);
    G[n+tot].push_back(v); G[v].push_back(n+tot);
}
void dfs(int v,int p,int d)
{
    int cnt=0;
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v,d+1);
        cnt++;
    }
    ans[d]=max(ans[d],cnt);
    maxd=max(maxd,d);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
    }
    int dep=INF;
    ll res=1LL*INF*INF;
    for(int i=1;i<=n+n-1;i++)
    {
        maxd=0; 
        memset(ans,0,sizeof(ans));
        dfs(i,0,0);
        ll tmp=1;
        for(int j=0;j<=maxd-1;j++) tmp=1LL*tmp*ans[j];
        if(maxd/2+1<dep||((maxd/2+1==dep)&&tmp<res))
        {
            dep=maxd/2+1;
            res=tmp;
        }
    }
    printf("%d %lld\n",dep,res);
    return 0;
}