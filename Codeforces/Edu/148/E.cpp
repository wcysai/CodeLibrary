#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 10000005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],x,y,m,k;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int main()
{
    scanf("%d%d%d%d%d%d",&n,&a[1],&x,&y,&m,&k);
    for(int i=2;i<=n;i++) a[i]=(1LL*a[i-1]*x+y)%m;
    for(int i=1;i<=k+1;i++)
        for(int j=1;j<=n+i;j++)
            add(a[j],a[j-1]);
    ll ans=0;
    for(int i=1;i<=n;i++){
        ll x=1LL*(i<k?0:a[i-k+1])*i;
        ans^=x;
    }
    printf("%lld\n",ans);
    return 0;
}

