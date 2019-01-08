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
typedef long double db;
int n;
db a[MAXN],b[MAXN],suma[MAXN],sumb[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%Lf%Lf",&a[i],&b[i]);
    sort(a+1,a+n+1,greater<>());sort(b+1,b+n+1,greater<>());
    for(int i=1;i<=n;i++) suma[i]=suma[i-1]+a[i];
    for(int i=1;i<=n;i++) sumb[i]=sumb[i-1]+b[i];
    db ans=0;
    for(int i=0;i<=n;i++)
    {
        int l=-1,r=n;
        while(r-l>1)
        {
            int mid=(l+r)/2;
            if(sumb[mid]>=suma[i]) r=mid; else l=mid;
        }
        ans=max(ans,min(sumb[r],suma[i])-(i+r));
        if(r!=0) ans=max(ans,min(sumb[r-1],suma[i])-i-(r-1));
    }
    printf("%.4Lf\n",ans);
    return 0;
}

