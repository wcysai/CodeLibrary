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
int t,a[MAXN];
ll n,k;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld",&n,&k);
        int cnt=0;
        for(ll i=1;i<=n;i*=3){
            int res=n%(3LL*i)/i;
            n-=res*i;
            cnt+=res;
        }
        if(k>=cnt&&(k-cnt)%2==0) puts("Yes"); else puts("No");
    }
    return 0;
}

