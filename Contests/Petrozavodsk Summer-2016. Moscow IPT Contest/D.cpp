#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,H;
int a[MAXN];
int main()
{
    scanf("%d%d",&n,&H);
    a[0]=H;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    double ans=a[n];
    for(int i=n-1;i>=0;i--)
    {
        int dif=a[i]-a[i+1];
        if(ans/2>=dif) continue;
        else ans+=(dif-ans/2);
    }
    printf("%.10f\n",ans);
    return 0;
}
