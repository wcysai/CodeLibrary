#include<bits/stdc++.h>
#define MAXN 16
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<double,double> P;
int n,k,a[MAXN];
double p1[MAXN],p2[MAXN];
P dp[20][(1<<8)][(1<<8)];
void upd(double &a,double b) {a+=b;}
void maxi(P &a,P b) {a=max(a,b);}
void mini(P &a,P b) 
{
    if(b.F+b.S<a.F+a.S) a=b;
    else if(b.F+b.S==a.F+a.S&&b.S>a.S) a=b;
}
void calc(int i,int mask1,int mask2)
{
    int x=__builtin_popcount(mask1);
    int y=__builtin_popcount(mask2);
    if(x==y) dp[i][mask1][mask2]=P(0.0,1.0);
    else if(x>y) dp[i][mask1][mask2]=P(1.0,0.0);
    else dp[i][mask1][mask2]=P(0.0,0.0);
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%lf",&p1[i]);
    for(int i=0;i<n;i++) scanf("%lf",&p2[i]);
    for(int mask1=0;mask1<(1<<n);mask1++)
        for(int mask2=0;mask2<(1<<n);mask2++)
            calc(2*n,mask1,mask2);
    for(int i=2*n-1;i>=0;i--)
    {
        for(int mask1=0;mask1<(1<<n);mask1++)
        {
            for(int mask2=0;mask2<(1<<n);mask2++)
            {
                if(mask1==0||mask2==0) calc(i,mask1,mask2);
                else if(i%2==0)
                {
                    int id=i/2;
                    if(!(mask1&(1<<id))) {dp[i][mask1][mask2]=dp[i+1][mask1][mask2]; continue;}
                    else dp[i][mask1][mask2]=P(0.0,0.0);
                    for(int j=0;j<n;j++)
                        if(mask2&(1<<j))
                        {
                            P p;
                            p.F=(1-p1[id])*dp[i+1][mask1][mask2].F+p1[id]*dp[i+1][mask1][mask2^(1<<j)].F;
                            p.S=(1-p1[id])*dp[i+1][mask1][mask2].S+p1[id]*dp[i+1][mask1][mask2^(1<<j)].S;
                            maxi(dp[i][mask1][mask2],p);
                        }
                }
                else
                {
                    int id=i/2;
                    if(!(mask2&(1<<id))) {dp[i][mask1][mask2]=dp[i+1][mask1][mask2]; continue;}
                    else dp[i][mask1][mask2]=P(1.0,0.0);
                    for(int j=0;j<n;j++)
                        if(mask1&(1<<j))
                        {
                            P p;
                            p.F=(1-p2[id])*dp[i+1][mask1][mask2].F+p2[id]*dp[i+1][mask1^(1<<j)][mask2].F;
                            p.S=(1-p2[id])*dp[i+1][mask1][mask2].S+p2[id]*dp[i+1][mask1^(1<<j)][mask2].S;
                            mini(dp[i][mask1][mask2],p);
                        }
                }
                //printf("%d %d %d %.10f %.10f\n",i,mask1,mask2,dp[i][mask1][mask2].F,dp[i][mask1][mask2].S);
            }
        }
    }
    printf("%.10f %.10f\n",dp[0][(1<<n)-1][(1<<n)-1].F,dp[0][(1<<n)-1][(1<<n)-1].S);
    return 0;
}