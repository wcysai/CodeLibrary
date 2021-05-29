#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
ll a[MAXN];
ll maxi[MAXN][MAXN],mini[MAXN][MAXN];
ll maxips[MAXN],minips[MAXN];
ll ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int len=2;len<=n;len+=2)
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            maxi[i][j]=(j==i+1?a[j]+a[i]:max(a[j]+a[i],maxi[i+1][j-1]));
            mini[i][j]=(j==i+1?a[j]+a[i]:min(a[j]+a[i],mini[i+1][j-1]));
        }
    maxips[0]=-INF,minips[0]=INF;
    for(int i=1;i<=n/2;i++)
    {
        maxips[i]=max(maxips[i-1],a[i]+a[n+1-i]);
        minips[i]=min(minips[i-1],a[i]+a[n+1-i]);
    }
    ans=INF;
    if(n%2==0) ans=min(ans,maxips[n/2]-minips[n/2]);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
        {
            int len=j-i+1;
            if((n-len)%2) continue;
            ll x=a[i],y=a[j];
            int l=i-1,r=n-j;
            if(l<=r)
            {
                x=min(x,minips[l]); y=max(y,maxips[l]);
                if(r>l) 
                {
                    x=min(x,mini[j+1][n-l]);
                    y=max(y,maxi[j+1][n-l]);
                }
                ans=min(ans,y-x);
            }
            else
            {
                x=min(x,minips[r]); y=max(y,maxips[r]);
                x=min(x,mini[r+1][i-1]);
                y=max(y,maxi[r+1][i-1]);
                ans=min(ans,y-x);
            }
        }
    printf("%lld\n",ans);
    return 0;
}