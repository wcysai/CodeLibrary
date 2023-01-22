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
int fact[MAXN];
int main()
{
    fact[0]=1;
    for(int i=1;i<=100000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int ans=(1LL*n*(n-1))%MOD*fact[n]%MOD;
        printf("%d\n",ans);
    }
    return 0;
}

