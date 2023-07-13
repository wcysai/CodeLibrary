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
int t,n,m,k,a[MAXN];
int fact[MAXN],invf[MAXN],inv[MAXN];
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
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
//f(a,b)=f(a-1,b-1)+(k-1)f(a-1,b);
//answer is f(m,n)
int main()
{
    fact[0]=invf[0]=1;
    for(int i=1;i<=200000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[200000]=pow_mod(fact[200000],MOD-2);
    for(int i=199999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    for(int i=1;i<=200000;i++) inv[i]=1LL*invf[i]*fact[i-1]%MOD;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&m,&k);
        int ans=pow_mod(k,m);
        for(int i=1;i<=n;i++){
            int x; scanf("%d",&x);
        }
        int c=1;
        for(int i=0;i<n;i++) 
        {
            dec(ans,1LL*c*pow_mod(k-1,m-i)%MOD);
            c=1LL*c*(m-i)%MOD*inv[i+1]%MOD;
        }
        printf("%d\n",ans);
    }
    return 0;
}

