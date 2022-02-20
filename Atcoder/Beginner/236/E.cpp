#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
double dp[MAXN];
int ddp[MAXN];
vector<int> v;
const double eps=1e-6;
bool check1(double x)
{
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1]+a[i]-x;
        if(i>=2) dp[i]=max(dp[i],dp[i-2]+a[i-1]-x);  else dp[i]=max(dp[i],0.0);
    }
    return dp[n]>=-eps;
}
bool check2(int x)
{
    ddp[0]=0;
    for(int i=1;i<=n;i++)
    {
        ddp[i]=ddp[i-1]+(a[i]>=x?1:-1);
        if(i>=2) ddp[i]=max(ddp[i],ddp[i-2]+(a[i-1]>=x?1:-1)); else ddp[i]=max(ddp[i],0);
    }
    return ddp[n]>0;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    double l=1.0,r=INF;
    for(int i=0;i<200;i++)
    {
        double mid=(l+r)/2;
        if(check1(mid)) l=mid; else r=mid;
    }
    printf("%.10f\n",l);
    int lb=0,rb=(int)v.size();
    while(rb-lb>1)
    {
        int mid=(lb+rb)/2;
        if(check2(v[mid])) lb=mid; else rb=mid;
    }
    printf("%d\n",v[lb]);
    return 0;
}