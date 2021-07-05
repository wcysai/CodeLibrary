#include<bits/stdc++.h>
#define MAXN 405
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,d[MAXN][MAXN],tmp[MAXN][MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            d[i][j]=(i==j?0:INF);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        d[u][v]=w;
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                tmp[j][k]=d[j][k];
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                tmp[j][k]=min(tmp[j][k],d[j][i]+d[i][k]);
        swap(tmp,d);
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                if(d[j][k]!=INF) ans+=d[j][k];
    }
    printf("%lld\n",ans);
    return 0;
}