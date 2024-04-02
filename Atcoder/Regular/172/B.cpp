#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,l,a[MAXN],fact[MAXN],invf[MAXN];
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
int solve(int x,int y){
    if(x<y) return 0;
    int res=invf[y];
    for(int i=x-y+1;i<=x;i++) res=1LL*res*i%MOD;
    return res;
}
int main(){
    fact[0]=invf[0]=1;
    for(int i=1;i<=500000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[500000]=pow_mod(fact[500000],MOD-2);
    for(int i=499999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d%d%d",&n,&k,&l);
    int ans=1;
    for(int i=1;i<=n-k+1;i++) ans=1LL*ans*(l+1-i)%MOD;
    ans=1LL*ans*pow_mod(l-(n-k),k-1)%MOD;
    printf("%d\n",ans);
    return 0;
}

