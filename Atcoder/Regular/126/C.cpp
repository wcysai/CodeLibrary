#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,cnt[MAXN];
ll s[MAXN];
ll res[MAXN];
ll sum,k;
int main()
{
    scanf("%d%lld",&n,&k);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        cnt[x]++; s[x]+=x;
    }
    for(int i=1;i<=300000;i++) {s[i]+=s[i-1]; cnt[i]+=cnt[i-1];}
    ll ans=0;
    for(int g=1;g<=300000;g++)
    {
        for(int i=1;i<=300000;i+=g)
        {
            int r=min(300000,i+g-1);
            ll ss=s[r]-s[i-1];
            int c=cnt[r]-cnt[i-1];
            res[g]+=1LL*c*(i+g-1)-ss;
        }
        if(res[g]<=k) ans=max(ans,1LL*g);
    }
    if(k>=300000LL*n-s[300000]) ans=max(ans,(s[300000]+k)/n);
    printf("%lld\n",ans);
    return 0;
}