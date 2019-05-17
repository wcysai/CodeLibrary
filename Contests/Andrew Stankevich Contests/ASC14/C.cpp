#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int a,b,c,d;
vector<int> G[MAXN];
int dp[MAXN][MAXN];
P last[MAXN][MAXN];
void die()
{
    puts("NO");
    exit(0);
}
int solve(int u,int v)
{
    if(dp[u][v]!=-1) return dp[u][v];
    dp[u][v]=0;
    if(u<v||v==d)
    {
        for(auto to:G[u])
        {
            if(to==v) continue;
            if(solve(to,v))
            {
                dp[u][v]=1;
                last[to][v]=P(u,v);
                return 1;
            }
        }
    }
    if(v<u||u==b)
    {
        for(auto to:G[v])
        {
            if(to==u) continue;
            if(solve(u,to))
            {
                dp[u][v]=1;
                last[u][to]=P(u,v);
                return 1;
            }
        }
    }
    return dp[u][v];
}
vector<int> pa,pb;
int main()
{
    freopen("express.in","r",stdin);
    freopen("express.out","w",stdout);
    scanf("%d%d",&n,&m);
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if(a>b) swap(a,b);
    if(c>d) swap(c,d);
    if(a==c||a==d||b==c||b==d) die();
    for(int i=0;i<m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        if(u<min(a,c)||v>max(b,d)) continue;
        G[u].push_back(v);
    }
    memset(dp,-1,sizeof(dp));
    dp[b][d]=1;
    if(!solve(a,c)) die();
    puts("YES");
    pa.push_back(b); pb.push_back(d);
    int x=b,y=d;
    while(x>a||y>c)
    {
        int nx=last[x][y].F,ny=last[x][y].S;
        if(x!=nx) {x=nx; pa.push_back(x);}
        else {y=ny; pb.push_back(y);}
    }
    reverse(pa.begin(),pa.end()); reverse(pb.begin(),pb.end());
    for(int i=0;i<(int)pa.size();i++) printf("%d ",pa[i]);
    puts("");
    for(int i=0;i<(int)pb.size();i++) printf("%d ",pb[i]);
    puts("");
}
