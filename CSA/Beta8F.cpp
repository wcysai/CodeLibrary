#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
ll comb(int n,int k)
{
    if(n-k<k) return comb(n,n-k);
    ll s=1;
    for(int i=n-k+1;i<=n;i++)
        s=s*i;
    for(int i=1;i<=k;i++)
        s=s/i;
    return s;
}
int n,cnt1,cnt2;
int main()
{
    scanf("%d",&n);
    cnt1=cnt2=0;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        if(x>=2) cnt2++;
        cnt1++;
    }
    ll ans=0;
    if(cnt1>=6) ans+=30*comb(cnt1,6);
    if(cnt1>=5&&cnt2>=1) ans+=3*comb(cnt1-1,4)*cnt2;
    if(cnt1>=4&&cnt2>=2) ans+=comb(cnt1-2,2)*comb(cnt2,2);
    if(cnt2>=3) ans+=comb(cnt2,3);
    printf("%lld\n",ans);
    return 0;
}
