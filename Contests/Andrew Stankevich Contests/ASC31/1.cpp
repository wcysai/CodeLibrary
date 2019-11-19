#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 4005
#define INF 1000000000
#define BASE 19260817
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<double> vec;
typedef vector<vec> mat;
int n,m,s,p[MAXN],w[MAXN];
double dp[MAXN],res[MAXN],ans[MAXN];
int main()
{
    scanf("%d%d%d",&n,&m,&s);
    for(int i=0;i<m;i++) scanf("%d%d",&p[i],&w[i]);
    dp[n+1]=1.0;
    for(int iter=0;iter<1000;iter++)
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int to=(i+w[j]>n?n+1:i+w[j]);
            double prob=(double)p[j]/s;
            double res=0.0;
            dp[i]=max(dp[i],prob*dp[to]+(1-prob)*dp[i-1]);
        }
    }
    printf("%.10f\n",dp[n]);
    return 0;
}
