#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x[MAXN],y[MAXN],p[MAXN];
ll ans[MAXN];
int distx[15][(1<<15)],disty[15][(1<<15)];
void solve(int mask,int submask)
{
    ll res=0;
    for(int i=0;i<n;i++)
    {
        if(!(mask&(1<<i))) 
        {
            int dist=min(max(x[i],-x[i]),max(y[i],-y[i]));
            dist=min(dist,distx[i][submask]);
            dist=min(dist,disty[i][mask^submask]);
            res+=1LL*dist*p[i];
        }
    }
    ans[__builtin_popcount(mask)]=min(ans[__builtin_popcount(mask)],res);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d%d%d",&x[i],&y[i],&p[i]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(1<<n);j++)
        {
            distx[i][j]=INF;
            for(int k=0;k<n;k++) if(j&(1<<k)) distx[i][j]=min(distx[i][j],max(x[i]-x[k],x[k]-x[i]));
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(1<<n);j++)
        {
            disty[i][j]=INF;
            for(int k=0;k<n;k++) if(j&(1<<k)) disty[i][j]=min(disty[i][j],max(y[i]-y[k],y[k]-y[i]));
        }
    }
    for(int i=0;i<=n;i++) ans[i]=1000000000000000000LL;
    for(int i=0;i<(1<<n);i++)
    {
        int sub=i;
        do
        {
            solve(i,sub);
            sub=(sub-1)&i;
        }while(sub!=i);
    }
    for(int i=0;i<=n;i++) printf("%lld\n",ans[i]);
    return 0;
}