#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,r,t,k;
vector<int> G[MAXN];
bool used[MAXN];
bool done[MAXN];
int match[MAXN];
void add_edge(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}
bool dfs(int v)
{
    used[v]=true;
    for(int i=0;i<(int)G[v].size();i++)
    {
        int u=G[v][i];
        int w=match[u];
        if(w<0||(!used[w]&&dfs(w)))
        {
            match[u]=v;
            return true;
        }
    }
    return false;
}
int rk[MAXN];
int main()
{
    freopen("contest.in","r",stdin);
    freopen("contest.out","w",stdout);
    scanf("%d%d%d%d%d",&n,&m,&r,&t,&k);
    for(int i=0;i<k;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,n+v);
    }
    memset(done,false,sizeof(done));
    int cnt=0;
    ll ans=0;
    memset(match,-1,sizeof(match));
    for(int turns=1;turns<=m&&turns*r<=t;turns++)
    {
        for(int j=1;j<=n;j++)
        {
            if(done[j]) continue;
            if(match[j]<0)
            {
                memset(used,false,sizeof(used));
                if(dfs(j))
                {
                    ans+=1LL*turns*r;
                    cnt++;
                    if(cnt==m) break;
                }
                else done[j]=true;
            }
        }
        if(cnt==m) break;
    }
    printf("%d %lld\n",cnt,ans);
    for(int i=n+1;i<=n+m;i++)
    {
        if(match[i]!=-1)
        {
            printf("%d %d %d\n",match[i],i-n,rk[match[i]]);
            rk[match[i]]+=r;
        }
    }
    return 0;
}
