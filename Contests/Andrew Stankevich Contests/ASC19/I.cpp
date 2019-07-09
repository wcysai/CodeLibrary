#include<bits/stdc++.h>
#define MAXN 2007
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef long double db;
int n;
int main()
{
    freopen("princess.in","r",stdin);
    freopen("princess.out","w",stdout);
    scanf("%d",&n);
    double ans=0.0;
    for(int r=0;r<n;r++)
    {
        double res=0.0;
        for(int i=r+1;i<=n;i++) res+=1.0/n*(i==1?1.0:(double)r/(i-1));
        ans=max(ans,res);
    }
    printf("%.10f\n",ans);
    return 0;
}
