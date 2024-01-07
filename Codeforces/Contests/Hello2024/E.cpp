#include<bits/stdc++.h>
#define MAXN 5025
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k,a[MAXN];
int p[MAXN],fact[MAXN],invf[MAXN];
int x[2*MAXN],y[2*MAXN],cnt[2*MAXN];//x[i+n]: i->i+1 y[i+n]: i+1->i
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
int comb(int n,int k){
    if(n<k) return 0;
    return 1LL*fact[n]*invf[k]%MOD*invf[n-k]%MOD;
}
int main(){
    fact[0]=invf[0]=1;
    for(int i=1;i<=5000;i++) fact[i]=1LL*fact[i-1]*i%MOD;
    invf[5000]=pow_mod(fact[5000],MOD-2);
    for(int i=4999;i>=1;i--) invf[i]=1LL*invf[i+1]*(i+1)%MOD;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<=2*n+5;i++) cnt[i]=x[i]=y[i]=0;
        int mini=0,maxi=0;
        for(int i=1;i<=n;i++) {scanf("%d",&p[i]); mini=min(mini,p[i]); maxi=max(maxi,p[i]); cnt[p[i]+n+1]++;}
        int ans=0;
        for(int stop=mini;stop<=maxi;stop++){
            bool f=true;
            for(int i=mini;i<=maxi;i++){
                int need=0; //indeg-odeg
                if(i==0) need--;
                if(i==stop) need++;
                int prex=x[i+n],prey=y[i+n];
                if(i==maxi){
                    if(prex!=cnt[i+n+1]||prex-prey!=need) f=false;
                }
                else{
                    y[i+n+1]=cnt[i+n+1]-prex;
                    x[i+n+1]=y[i+n+1]+prex-prey-need;
                    if(x[i+n+1]<0||y[i+n+1]<0) {f=false; break;}
                }
            }
            if(f){
               // for(int i=mini;i<=maxi-1;i++) printf("%d %d\n",x[i+n+1],y[i+n+1]);
                int res=1;
                for(int i=mini;i<=maxi;i++){
                    if(stop==i) res=1LL*res*comb(y[i+n]+x[i+n+1],y[i+n])%MOD;
                    else if(stop<i){
                        if(!y[i+n]) {res=0; break;}
                        res=1LL*res*comb(y[i+n]+x[i+n+1]-1,y[i+n]-1)%MOD;
                    }
                    else{
                        if(!x[i+n+1]) {res=0; break;}
                        res=1LL*res*comb(y[i+n]+x[i+n+1]-1,y[i+n])%MOD;
                    }
                }
                add(ans,res);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

