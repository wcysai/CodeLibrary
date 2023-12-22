#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int k,mod;
int pow_mod(int a,ll i){
    int s=1;
    while(i){
        if(i&1) s=1LL*s*a%mod;
        a=1LL*a*a%mod;
        i>>=1;
    }
    return s;
}
int fact[10005],invf[10005];
void add(int &a,int b) {a+=b; if(a>=mod) a-=mod;}
void dec(int &a,int b) {a-=b; if(a<0) a+=mod;}
int comb(int n,int k){
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%mod*invf[n-k]%mod;
}
vector<int> solve(int k,ll n){
    if(n==0){
        vector<int> ret(k,0);
        ret[0]=1;
        return ret;
    }
    if(n&1){
        vector<int> last=solve(k,n-1);
        vector<int> ret(k,0);
        int sum=0; 
        for(int i=0;i<k;i++) add(sum,last[i]);
        vector<int> banned;
        banned.push_back(0);
        if(k%2==0) banned.push_back(k/2); 
        for(int i=0;i<k;i++){
            ret[i]=sum;
            for(auto x:banned) dec(ret[i],last[(i+k-x)%k]);
        }
        return ret;
    }
    else{
        vector<int> last=solve(k,n/2);
        vector<int> ret(k,0);
        for(int i=0;i<k;i++)
            for(int j=0;j<k;j++)
                add(ret[(i+j)%k],1LL*last[i]*last[j]%mod);
        return ret;
    }
}
int main(){
    scanf("%lld%d%d",&n,&k,&mod);
    fact[0]=invf[0]=1;
    for(int i=1;i<=10000;i++) fact[i]=1LL*fact[i-1]*i%mod;
    invf[10000]=pow_mod(fact[10000],mod-2);
    for(int i=9999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%mod;
    vector<int> res=solve(k,n);
    int ans=pow_mod(k,n);
    if(k%2==0) ans=(1LL*ans*(mod+1)/2)%mod;
    if(k&1){
        for(int i=0;i<k;i++){
            int need;
            if(i&1) need=(k+i)/2; else need=i/2;
            int sum=(i-1LL*(n%k)*need%k+k)%k;
            dec(ans,res[sum]);
        }
    }
    else{
        for(int i=0;i<k;i++){
            if(i&1) continue;
            int need=i/2;
            int sum=(i-1LL*(n%k)*need%k+k)%k;
            dec(ans,res[sum]);
        }
    }
    printf("%d\n",ans);
    return 0;
}

