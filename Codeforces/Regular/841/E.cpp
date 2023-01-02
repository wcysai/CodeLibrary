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
int t,n;
ll m;
ll cnt[MAXN];
ll num[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%lld",&n,&m);
        for(int i=1;i<=n;i++) cnt[i]=0;
        for(int i=n;i>=1;i--){
            cnt[i]=1LL*(n/i)*(n/i-1)/2;
            for(int j=2*i;j<=n;j+=i) cnt[i]-=cnt[j];
        }
        ll all=1LL*n*(n-1)/2;
        for(int i=1;i<=n-1;i++){
            num[i]=cnt[i+1]/i;
            all-=cnt[i+1]%i;
        }
        all-=cnt[1];
        if(all<m) {puts("-1"); continue;}
        ll x=0,tmp=m;
        for(int i=n-1;i>=1;i--){
            ll q=min(1LL*num[i],m/i);
            x+=q; m-=q*i;
        }
        printf("%lld\n",tmp+x);
    }
    return 0;
}

