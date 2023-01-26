#pragma GCC optimize(3)
#include<iostream>
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ll s=0,x=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            s+=a[i];
        }
        ll ans=0;
        for(int i=1;i<=n-1;i++){
            x+=a[i];
            ans=max(ans,gcd(x,s-x));
        }
        printf("%lld\n",ans);
    }
    return 0;
}

