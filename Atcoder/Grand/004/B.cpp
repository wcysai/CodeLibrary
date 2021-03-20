#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],x;
int mini[MAXN][MAXN];
int compute_minimum(int s,int t)
{
    if(s<=t) return mini[s][t];
    else return min(mini[s][n],mini[1][t]);
}
int main()
{
    scanf("%d%d",&n,&x);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        mini[i][i]=a[i];
        for(int j=i+1;j<=n;j++) mini[i][j]=min(mini[i][j-1],a[j]);
    }
    ll ans=INF;
    for(int i=0;i<=n-1;i++)
    {
        ll sum=1LL*i*x;
        for(int j=1;j<=n;j++)
        {
            int t=j,s=j-i;
            while(s<=0) s+=n;
            sum+=compute_minimum(s,t);
        }
        ans=min(ans,sum);
    }
    printf("%lld\n",ans);
    return 0;
}