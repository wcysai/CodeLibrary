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
int main(){
    scanf("%d",&t);
    while(t--){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(a[n]!=n) {puts("0"); continue;}
    bool f=true;
    for(int i=1;i<=n;i++) if(a[i]>i) {f=false; break;}
    if(!f) {puts("0"); continue;}
    dp[0]=1;
    for(int i=1;i<=n;i++){
        if(a[i]==a[i-1]){
            dp[i]=dp[i-1];
        }
        else if(a[i]==a[i-1]+1){//put any valid number in i+1 or puts i+1 in any position before
            int valid=(i-1)-a[i-1];
            dp[i]=1LL*dp[i-1]*(2*valid+1)%MOD;
        }
        else if(a[i]==a[i-1]+2){//puts i+1 before and any number in i+1
            int valid=(i-1)-a[i-1];
            dp[i]=1LL*dp[i-1]*(valid)%MOD*valid%MOD;
        }
        else dp[i]=0;
    }
    printf("%d\n",dp[n]);
    }
    return 0;
}

