#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll Q,n,m,k;
ll D;
ll t[MAXN];
ll sum[MAXN];
int main()
{
    scanf("%lld",&Q);
    while(Q--)
    {
        scanf("%lld%lld%lld%lld",&n,&m,&k,&D);
        for(ll i=1;i<=m;i++) scanf("%lld",&t[i]);
        sort(t+1,t+m+1);
        sum[m+1]=0;
        for(ll i=m;i>=1;i--) sum[i]=sum[i+1]+t[i];
        ll ans=0,need=0;
        for(ll finished=0;finished<=m;finished++)
        {
            if(need>D) break;
            if(finished==m)
            {
                ans=1LL*n*m+1LL*n*k;
                break;
            }
            ll rest=D-need;
            ans=max(ans,1LL*finished*n+min(1LL*n,rest/t[finished+1]));
            if(finished!=m-1)
            {
                ll least=(rest-1LL*n*t[finished+1])/(sum[finished+2])+1;
                ll rem=rest-1LL*least*sum[finished+1];
                if(rem>=0&&least>=0&&least<=n) ans=max(ans,1LL*finished*n+1LL*least*k+1LL*least*(m-finished)+min(n-least,rem/t[finished+1]));
            }
            ll full=rest/(sum[finished+1]);
            if(full>=n)
            {
                ans=1LL*n*m+1LL*n*k;
                break;
            }
            rest-=1LL*full*sum[finished+1];
            ans=max(ans,1LL*finished*n+1LL*full*k+1LL*full*(m-finished)+min(n-full,rest/t[finished+1]));
            need+=1LL*t[finished+1]*n;
        }
        printf("%lld\n",ans);
    }
}

