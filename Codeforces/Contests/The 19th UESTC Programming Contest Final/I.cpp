#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n;
ll a[MAXN];
ll dp[MAXN][2][2][3][3][3];
ll get_cost(int x,int y)
{
    return max(a[x]-a[y],a[y]-a[x]);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        ll delta=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        if(n==2)
        {
            printf("%lld\n",get_cost(1,2));
            continue;
        }
        delta=max(delta,get_cost(1,n-1)+get_cost(2,n)-get_cost(1,2)-get_cost(n-1,n));//swap(1,n)
        delta=max(delta,get_cost(1,3)-get_cost(2,3)); //swap(1,2)
        delta=max(delta,get_cost(n-2,n)-get_cost(n-2,n-1));//swap(n-1,n)
        for(int i=3;i<=n-1;i++) delta=max(delta,get_cost(1,i+1)+get_cost(1,i-1)+get_cost(i,2)-get_cost(1,2)-get_cost(i,i+1)-get_cost(i,i-1));//swap(1,i)
        for(int i=n-2;i>=2;i--) delta=max(delta,get_cost(n,i+1)+get_cost(n,i-1)+get_cost(i,n-1)-get_cost(n,n-1)-get_cost(i,i+1)-get_cost(i,i-1));//swap(i,n)
        ll ans=0;
        for(int i=2;i<=n;i++) ans+=get_cost(i-1,i);
        ans+=delta;
        for(int i=1;i<=n;i++)
            for(int state=0;state<2;state++)
                for(int used=0;used<2;used++)
                    for(int x=0;x<3;x++)
                        for(int y=0;y<3;y++)
                            for(int z=0;z<3;z++)
                                dp[i][state][used][x][y][z]=-INF;
        dp[1][0][0][1][1][1]=-a[1]; dp[1][1][0][1][1][1]=a[1];
        for(int i=1;i<=n-1;i++)
        {
            for(int state=0;state<2;state++)
                for(int used=0;used<2;used++)
                {
                    for(int j=0;j<3;j++)
                    {
                        for(int k=0;k<3;k++)
                        {
                            for(int l=0;l<3;l++)
                            {
                                if(dp[i][state][used][j][k][l]==-INF) continue;
                                if(i==n-1)
                                {
                                    if(!used) continue;
                                    if(j!=1||k!=1||l!=1) continue;
                                    if(state==0) ans=max(ans,dp[i][state][used][j][k][l]+a[n]);
                                    if(state==1) ans=max(ans,dp[i][state][used][j][k][l]-a[n]);
                                }
                                for(int x=0;x<3;x++)
                                    for(int y=0;y<3;y++)
                                    {
                                        if(state+x-1<0||state+x-1>1) continue;
                                        if(used&&(x!=y)) continue;
                                        int nj=j,nk=k,nl=l;
                                        if(x==0) nj--; else if(x==1) nk--; else nl--;
                                        if(y==0) nj++; else if(y==1) nk++; else nl++;
                                        int nused=used;
                                        if(j!=1||k!=1||l!=1)
                                        {
                                            if(x!=y&&(nj!=1||nk!=1||nl!=1)) continue;
                                            if(x!=y) nused=1;
                                        } 
                                        ll delta=0;
                                        if(y==0) delta+=-2*a[i+1]; else if(y==1) delta+=0; else delta+=2*a[i+1];
                                        dp[i+1][state+x-1][nused][nj][nk][nl]=max(dp[i+1][state+x-1][nused][nj][nk][nl],dp[i][state][used][j][k][l]+delta);
                                    }
                            }
                        }
                    }
                }
        }
        printf("%lld\n",ans);
    }
    return 0;
}