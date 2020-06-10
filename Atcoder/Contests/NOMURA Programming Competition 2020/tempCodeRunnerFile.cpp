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
ll suf[MAXN];
ll ans[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<=n;i++) scanf("%d",&a[i]);
    suf[n]=a[n];
    for(int i=n-1;i>=0;i--) suf[i]=suf[i+1]+a[i];
    ans[0]=1;
    for(int i=1;i<=n;i++) 
    {
        if(ans[i-1]<a[i-1])
        {
            puts("-1");
            return 0;
        }
        ans[i]=min((ans[i-1]-a[i-1])*2,suf[i]);
    }
    ll res=0;
    for(int i=0;i<=n;i++) res+=ans[i];
    printf("%lld\n",res);
    return 0;
}