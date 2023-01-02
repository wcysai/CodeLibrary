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
int t,n,k,a[MAXN];
int pow_mod(int a,int i){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int main()
{
    int inv=pow_mod(6,MOD-2);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ans=1LL*n*(n+1)%MOD*(4LL*n-1)%MOD*inv%MOD*2022%MOD;
        printf("%d\n",ans);
    }
    return 0;
}

