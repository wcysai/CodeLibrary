#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 20
#define MAXM (1<<20)
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
int zero[MAXN],one[MAXN];
int dp[MAXM];
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
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int t,x,y;
        scanf("%d%d%d",&t,&x,&y);
        x--; y--;
        if(t==0){
            zero[x]|=(1<<y);
            zero[y]|=(1<<x);
        }
        else{
            one[x]|=(1<<y);
            one[y]|=(1<<x);
        }
    }
    dp[0]=1;
    for(int mask=1;mask<(1<<n);mask++){
        for(int j=0;j<n;j++){
            if(!(mask&(1<<j))) continue;
            int sub=mask^(1<<j);
            if((zero[j]&sub)==zero[j]) add(dp[mask],dp[sub]);
            if((one[j]&sub)==one[j]) add(dp[mask],dp[sub]);
        }
    }
    int fact=1;
    for(int i=1;i<=n;i++) fact=1LL*fact*i%MOD;
    int ans=dp[(1<<n)-1];
    ans=1LL*ans*pow_mod(fact,MOD-2)%MOD;
    int num=pow_mod(2,n);
    ans=1LL*ans*pow_mod(num,MOD-2)%MOD;
    printf("%d\n",ans);
    return 0;
}

