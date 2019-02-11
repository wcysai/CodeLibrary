#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int ans=INF;
    for(int i=1;i+k-1<=n;i++)
    {
        int j=i+k-1;
        if(a[i]>=0) ans=min(ans,a[j]);
        else if(a[j]<=0) ans=min(ans,-a[i]);
        else ans=min(ans,min(a[j]-2*a[i],-a[i]+2*a[j]));
    }
    printf("%d\n",ans);
    return 0;
}

