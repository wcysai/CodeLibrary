#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int fact[MAXN],invf[MAXN],cata[MAXN];
ull val[MAXN];
mt19937_64 wcy(time(NULL));
map<ull,int> mp;
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
    fact[0]=invf[0]=1;
    for(int i=1;i<=300000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[300000]=pow_mod(fact[300000],MOD-2);
    for(int i=299999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    for(int i=1;i<=150000;i++){
        cata[i]=1LL*invf[i+1]*fact[i]%MOD*comb(2*i,i)%MOD;
    }
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) val[i]=0;
        for(int i=0;i<k;i++){
            int l,r; scanf("%d%d",&l,&r);
            ull x=wcy();
            val[l]^=x; val[r+1]^=x;
        }
        mp.clear();
        for(int i=1;i<=n;i++){
            val[i]^=val[i-1];
            mp[val[i]]++;
        }
        int ans=1;
        for(auto p:mp){
            if(p.S&1) {ans=0; break;}
            else ans=1LL*ans*cata[p.S/2]%MOD;
        }
        printf("%d\n",ans);
    }
    return 0;
}

