#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN],dp[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int pow_mod(int a,int i){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
int fact[MAXN],invf[MAXN];
int comb(int n,int k){
    if(n<k||n<0||k<0) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int calc(int last,int cur,int la,int ca,int val){
    //printf("val=%d\n",val);
    if(last==cur){
        if(la==ca) return val; else return 0;
    }
    if(last<la||cur<ca) return 0;
    if(ca<la) return 0;
    int valid=last-la;
    int num=ca-la;
    int pos=cur-last;
    int res=0;
    for(int i=0;i<=min(valid,pos);i++){//enumerating on the number of valid to be put in [last+1,cur]
        int z=num-i;
        add(res,1LL*val*comb(valid,i)%MOD*comb(pos,i)%MOD*fact[i]%MOD*comb(pos,z)%MOD*comb(valid+pos-i,z)%MOD*fact[z]%MOD);
    }
    //printf("res=%d\n",res);
    return res;
}
int main(){
    fact[0]=invf[0]=1;
    for(int i=1;i<=200000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[200000]=pow_mod(fact[200000],MOD-2);
    for(int i=199999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        vector<P> v; v.push_back(P(0,0));
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]); if(a[i]!=-1) v.push_back(P(i,a[i]));}
        v.push_back(P(n,n));
        dp[0]=1;
        for(int i=1;i<(int)v.size();i++) dp[i]=calc(v[i-1].F,v[i].F,v[i-1].S,v[i].S,dp[i-1]);
        printf("%d\n",dp[(int)v.size()-1]);
    }
    return 0;
}

