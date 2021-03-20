#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,t,e,x[MAXN];
ll dp[MAXN],pre[MAXN];
int main()
{
    scanf("%d%d%d",&n,&e,&t);
    for(int i=1;i<=n;i++) scanf("%d",&x[i]);
    for(int i=1;i<=n;i++)
    {
        if(2*(x[i]-x[1])<=t) dp[i]=t;
        else
        {
            dp[i]=INF;
            int l=1,r=i;
            while(r-l>1)
            {
                int mid=(l+r)/2;
                if(2*(x[i]-x[mid])<=t) r=mid; else l=mid;
            }
            dp[i]=min(dp[i],dp[r-1]+max(t,2*(x[i]-x[r])));
            dp[i]=min(dp[i],pre[r-1]+2*x[i]);
        }
        if(i==1) pre[i]=-2*x[i]; else pre[i]=min(pre[i-1],dp[i-1]-2*x[i]);
    }
    printf("%lld\n",dp[n]+e);
    return 0;
}