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
int t,n,fact[MAXN],invf[MAXN],p2[MAXN];
string a,b;
int pow_mod(int a,int i){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int comb(int n,int k){
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main()
{
    p2[0]=fact[0]=invf[0]=1;
    for(int i=1;i<=200000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[200000]=pow_mod(fact[200000],MOD-2);
    for(int i=199999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    for(int i=1;i<=200000;i++) p2[i]=2LL*p2[i-1]%MOD;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        cin>>a>>b;
        int dif=0;
        for(int i=0;i<n;i++) if(a[i]!=b[i]) dif++;
        if(dif&1) printf("0\n");
        else printf("%d\n",1LL*p2[n-dif]*comb(dif,dif/2)%MOD);
    }
    return 0;
}

