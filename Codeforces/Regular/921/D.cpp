#include<bits/stdc++.h>
#define MAXN 4005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,k,a[MAXN];
int fact[MAXN],invf[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
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
    if(k<0||n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int calc(int n,int m,int need){//number of ways that prefix of ) never exceeds ( + need 
    if(need<0) return 0;
    if(need>=m) return comb(n+m,n);
    int res=comb(n+m,n);
    //reflection
    dec(res,comb(n+m,m-need-1));
    return res;
}
int main(){
    fact[0]=invf[0]=1;
    for(int i=1;i<=4000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[4000]=pow_mod(fact[4000],MOD-2);
    for(int i=3999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        if(k>min(n,m)) {puts("0"); continue;}
        int need=min(n,m)-k;
        //printf("need=%d\n",need);
        int ans=calc(n,m,need);
        //printf("ans=%d\n",ans);
        dec(ans,calc(n,m,need-1));
        printf("%d\n",ans);
    }
    return 0;
}

