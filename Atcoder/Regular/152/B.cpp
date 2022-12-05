#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,L,a[MAXN];
int main()
{
    scanf("%d%d",&n,&L);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    ll ans=INF;
    for(int i=1;i<=n;i++)
    {
        int t1=2*a[i],t2=2*(L-a[i]);
        if(t1<t2)
        {
            int l=i,r=n+1;
            while(r-l>1)
            {
                int mid=(l+r)/2;
                if(t1+(a[mid]-a[i])<=t2-(a[mid]-a[i])) l=mid; else r=mid;
            }
            ans=min(ans,2LL*(t2-(a[l]-a[i])));
        }
        else
        {
            int l=0,r=i;
            while(r-l>1)
            {
                int mid=(l+r)/2;
                if(t2+(a[i]-a[mid])<=t1-(a[i]-a[mid])) r=mid; else l=mid;
            }
            ans=min(ans,2LL*(t1-(a[i]-a[r])));
        }
    }
    printf("%lld\n",ans);
    return 0;
}

