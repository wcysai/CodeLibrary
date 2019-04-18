#include<bits/stdc++.h>
#define MAXN 105
#define MAXM 20005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,k;
vector<int> G[MAXN];
int u[MAXM],v[MAXM];
int dfn[MAXN],low[MAXN],st[MAXN];
int cmp[MAXN],vis[MAXN],cnt,tot,t;
int indeg[MAXN],outdeg[MAXN],sz[MAXN];
void dfs(int v)
{
    dfn[v]=low[v]=++tot;
    vis[v]=1;
    st[t++]=v;
    for(auto to:G[v])
    {
        if(!vis[to])
        {
            dfs(to);
            low[v]=min(low[v],low[to]);
        }
        else if(vis[to]==1) low[v]=min(low[v],dfn[to]);
    }
    if(dfn[v]==low[v])
    {
        int u;
        do
        {
            u=st[t-1]; t--;
            cmp[u]=cnt;
            vis[u]=2;
        }while(u!=v);
        cnt++;
    }
}
int tarjan()
{
    t=tot=cnt=0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++) if(!dfn[i]) dfs(i);
    return cnt;
}
struct bigint
{
    bigint(){}
    vector<int> v;
    void clear()
    {
        v.clear();
        v.push_back(0);
    }
    void set(int x)
    {
        v.clear();
        while(x) {v.push_back(x%10); x/=10;}
        reverse(v.begin(),v.end());
    }
    void add(bigint &rhs)
    {
        int sz=(int)max(v.size(),rhs.v.size());
        int carry=0;
        for(int i=0;i<sz;i++)
        {
            if((int)v.size()<=i) v.push_back(0);
            int res=v[i]+((int)rhs.v.size()<=i?0:rhs.v[i])+carry;
            v[i]=res%10;
            carry=res/10;
        }
        if(carry) v.push_back(carry);
    }
    void print()
    {
        int sz=(int)v.size();
        for(int i=sz-1;i>=0;i--) printf("%d",v[i]);
        printf("\n");
    }
    void pton()
    {
        while(v.size()>0&&v.back()==0) v.pop_back();
    }
    bool iszero()
    {
        pton();
        return v.size()==0;
    }
};
vector<int> need;
bigint dp[MAXN][MAXN][2];
int main()
{
    freopen("police.in","r",stdin);
    freopen("police.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&u[i],&v[i]);
        G[u[i]].push_back(v[i]);
    }
    int p=tarjan();
    for(int i=1;i<=n;i++) sz[cmp[i]]++;
    for(int i=0;i<m;i++)
    {
        if(cmp[u[i]]!=cmp[v[i]])
        {
            outdeg[cmp[u[i]]]++;
            indeg[cmp[v[i]]]++;
        }
    }
    int sum=0;
    for(int i=0;i<=p;i++)
    {
        if(outdeg[i]&&indeg[i]) continue;
        sum+=sz[i];
        for(int j=0;j<sz[i];j++) need.push_back(i); 
    }
    for(int i=0;i<n-sum;i++) need.push_back(p+1);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            for(int k=0;k<2;k++)
                dp[i][j][k].clear();
    dp[0][0][0].set(1);
    for(int i=0;i<(int)need.size();i++)
    {
        bool last=(need[i]!=p+1)&&(i==(int)need.size()-1||need[i]!=need[i+1]);
        bool transit=(i==(int)need.size()-1||need[i]!=need[i+1]);
        for(int j=0;j<=k;j++)
        {
            for(int l=0;l<2;l++)
            {
                //printf("%d %d %d ",i,j,l);
                //dp[i][j][l].print();
                if(dp[i][j][l].iszero()) continue;
                if(!last||l) dp[i+1][j][transit?0:l].add(dp[i][j][l]);
                if(j!=k) dp[i+1][j+1][transit?0:1].add(dp[i][j][l]);
            }
        }
    }
    dp[n][k][0].print();
    return 0;
}
