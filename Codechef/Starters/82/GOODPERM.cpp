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
int T,n,k,a[MAXN],b[MAXN],ans;
int fact[MAXN],invf[MAXN];
map<ll,int> mpa,mpb,tmp;
int pow_mod(int a,int i){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int comb(int n,int k){
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int solve(ll sum){
    tmp=mpb;
    int ret=1;
    for(auto p:mpa){
        ll need=sum-p.F;
        need=max(need,-need);
        int rem=tmp[need];
        if(rem<p.S) return 0;
        ret=1LL*ret*fact[rem]%MOD*invf[rem-p.S]%MOD;
        tmp[need]-=p.S;
    }
    return ret;
}
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=100000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[100000]=pow_mod(fact[100000],MOD-2);
    for(int i=99999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d",&T);
    while(T--){
        mpa.clear(); mpb.clear(); ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]); mpa[a[i]]++;} 
        for(int i=1;i<=n;i++) {scanf("%d",&b[i]); mpb[max(-b[i],b[i])]++;}
        sort(a+1,a+n+1);
        sort(b+1,b+n+1);
        int val=max(max(b[1],-b[1]),max(b[n],-b[n]));
        add(ans,solve(a[1]+val));
        if(a[1]!=a[n]&&a[1]+val!=a[n]-val) add(ans,solve(a[n]-val));
        printf("%d\n",ans);
    }
    return 0;
}

