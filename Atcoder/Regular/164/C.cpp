#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN],b[MAXN],c[MAXN];
int main()
{
    scanf("%d",&n);
    ll ans=0;
    for(int i=1;i<=n;i++) {
        scanf("%d%d",&a[i],&b[i]);
        ans+=a[i]; c[i]=b[i]-a[i];
    }
    sort(c+1,c+n+1,greater<int>());
    ll res=0,sum=0;
    int now=0;
    if(n&1) {now=1; sum=res=c[1];}
    for(int i=now+2;i<=n;i+=2){
        sum+=c[i-1]+c[i];
        res=max(res,sum);
    }
    printf("%lld\n",ans+res);
    return 0;
}

