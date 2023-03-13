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
int t,n,k,x;
ll a[MAXN];
ll s[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&k,&x);
        for(int i=1;i<=n;i++) 
        {
            scanf("%lld",&a[i]);
            a[i]-=x;
            s[i]=s[i-1]+a[i];
        }
        x*=2;
        if(x>=0)
        {
            ll ans=0,mini=INF;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=min(i,k);j++){
                    ans=max(ans,s[i]-s[i-j]+1LL*j*x);
                }
                if(i>=k){
                    mini=min(mini,s[i-k]);
                    ans=max(ans,s[i]-mini+1LL*k*x);
                }
            }
            printf("%lld\"n",ans);
        }
        else{
            ll ans=0;
            multiset<ll> ms;
            for(int i=1;i<=n;i++){
                ms.insert(s[i-1]);
                if(i>n-k) ms.erase(ms.find(s[i-(n-k)-1]));
                if(ms.size()) ans=max(ans,s[i]-*ms.begin());
            }
            for(int i=1;i<=n;i++)
                for(int j=i+(n-k);j<=n;j++){
                    int len=j-i+1;
                    ans=max(ans,s[j]-s[i-1]+1LL*(len-(n-k))*x);
                }
            printf("%lld\n",ans);
        }
    }
    return 0;
}

