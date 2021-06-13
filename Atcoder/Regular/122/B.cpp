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
int main()
{
    scanf("%d",&n);
    double sum=0.0;
    for(int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    sort(a+1,a+n+1);
    double ans=sum/n;
    double s=0.0;
    for(int i=1;i<=n;i++)
    {
        double x=a[i]/2.0; s+=a[i];
        ans=min(ans,sum/n+x-(double)s/n-2.0*x*(n-i)/n);
    }
    printf("%.10f\n",ans);
    return 0;
}