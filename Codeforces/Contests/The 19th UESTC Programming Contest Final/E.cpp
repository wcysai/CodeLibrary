#include<bits/stdc++.h>
#define MAXN 23
#define MAXM (1<<22)
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
vector<P> G[MAXN];
int a[MAXN];
ll wt[MAXN][MAXN];
ll inmask[MAXN],outmask[MAXN];
ll weight[MAXM];
bool loop[MAXN];
ll dp1[MAXM],dp2[MAXM];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                wt[i][j]=0;
        for(int i=0;i<n;i++) inmask[i]=outmask[i]=0,loop[i]=false;
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<(1<<n);i++)
        {
            weight[i]=0;
            for(int j=0;j<n;j++) if(i&(1<<j)) weight[i]+=a[j];
        }
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            u--; v--;
            inmask[v]|=(1LL<<u); outmask[u]|=(1LL<<v);
            if(u==v) loop[u]=true;
            G[u].push_back(P(v,w));
            G[v].push_back(P(u,w));
            wt[u][v]+=w;
        }
        for(int i=0;i<(1<<n);i++)
        {
            if(i==0) dp1[i]=0; else dp1[i]=INF;
            for(int j=0;j<n;j++)
                if(i&(1<<j))
                {
                    dp1[i]=min(dp1[i],dp1[i^(1<<j)]+a[j]);
                    if(!loop[j]) dp1[i]=min(dp1[i],dp1[(i&(~inmask[j]))^(1<<j)]+weight[(i&inmask[j])]);
                }
        }
        for(int i=0;i<(1<<n);i++)
        {
            if(i==0) dp2[i]=0; else dp2[i]=INF;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    ll res=0;
                    for(int k=0;k<n;k++) if(i&(1<<k)) res+=wt[k][j];
                    dp2[i]=min(dp2[i],dp2[i^(1<<j)]+res);
                }
            }
        }
        printf("%lld %lld\n",dp1[(1<<n)-1],dp2[(1<<n)-1]);
    }
    return 0;
}