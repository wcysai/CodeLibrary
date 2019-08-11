#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 405
#define MAXD 15
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef bitset<400> bs;
int n,q,A,B;
bs b[MAXN];
bool a[MAXN][MAXN];
unsigned pa[MAXN],pb[MAXN];
char ch1[3],ch2[3];
bool vis[MAXN];
void dfs(int v)
{
    if(vis[v]) return;
    vis[v]=true;
    for(int i=1;i<=n;i++)
    {
        if(a[v][i])
        {
            dfs(i);
            b[v]|=b[i];
        }
    }
}
unsigned solve()
{
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        b[i].reset();
        b[i].set(i-1);
    }
    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
    unsigned ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            if(b[i].test(j-1)) ans+=pa[i-1]*pb[j-1];
        }
    return ans;
}
int main()
{
    freopen("reachability.in","r",stdin);
    freopen("reachability.out","w",stdout);
    scanf("%d%d%d%d",&n,&q,&A,&B);
    pa[0]=pb[0]=1;
    for(int i=1;i<=400;i++) pa[i]=pa[i-1]*A,pb[i]=pb[i-1]*B;
    memset(a,false,sizeof(a));
    for(int i=0;i<q;i++)
    {
        scanf("%s",ch1);
        scanf("%s",ch2);
        int v,k;
        scanf("%d%d",&v,&k);
        for(int j=0;j<k;j++)
        {
            int x;
            scanf("%d",&x);
            if(ch2[0]=='o') a[v][x]=!a[v][x]; else a[x][v]=!a[x][v];
        }
        printf("%u\n",solve());
    }
    return 0;
}
