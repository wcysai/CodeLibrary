#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,k,a[MAXN];
int dp[61][125];
int f[61],g[61];
int p2[120];
ll n;
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
int main()
{
    p2[0]=1;
    for(int i=1;i<=100;i++) p2[i]=2LL*p2[i-1]%MOD;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        if(n==1) {printf("0\n"); continue;}
        n--;
        int ans=0;
        for(int mult=0;(1LL<<mult)<=n;mult++){
            int cf=pow_mod(p2[mult],MOD-2),res=0;
            ll z=n-(1LL<<mult);
            //printf("mult=%d z=%lld\n",mult,z);
            int st=60;
            memset(dp,0,sizeof(dp));
            dp[st][0]=1;
            int maxi=2*st;
            for(int i=st;i>=0;i--){
                vector<int> v;
                for(int j=0;j<=i;j++){
                    if(i-j>mult) continue;
                    int x=pow_mod(2,(1LL<<j)%(MOD-1));
                    v.push_back(pow_mod(x,MOD-2));
                }
                memset(f,0,sizeof(f)); memset(g,0,sizeof(g));
                f[0]=1;
                for(int j=0;j<(int)v.size();j++){
                    memset(g,0,sizeof(g));
                    for(int k=0;k<=j;k++){
                        if(!f[k]) continue;
                        add(g[k],f[k]); add(g[k+1],1LL*f[k]*v[j]%MOD);
                    }
                    swap(f,g);
                }
                int nxt=(i==0?0:((z>>(i-1))&1));
                for(int j=0;j<maxi;j++){
                    if(!dp[i][j]) continue;
                    //printf("mult=%d i=%d j=%d dp=%d\n",mult,i,j,dp[i][j]);
                    for(int k=0;k<=min(j,(int)v.size());k++){
                        int val=min(2*(j-k)+nxt,maxi-1);
                        if(i==0) {
                            add(res,1LL*dp[i][j]*f[k]%MOD); 
                        }
                        else{ 
                            add(dp[i-1][val],1LL*dp[i][j]*f[k]%MOD);
                        }
                    }
                }
            }
            add(ans,1LL*res*cf%MOD);
        }
        printf("%d\n",ans);
    }
    return 0;
}

