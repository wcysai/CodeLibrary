#pragma GCC optimize(3)
#include<iostream>
#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,l;
char str[MAXN];
int s[MAXN],sum[MAXN];
P dp[MAXN];
P check(int cost){
    dp[0]=P(0,0);
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        if(s[i]) dp[i].F++;
        if(i>=l) {
            P p=dp[i-l]; p.F+=l-cost; p.S++;
            if(p.F>dp[i].F) dp[i]=p;
        }
        else{
            if(dp[i].F<i-cost) dp[i]=P(i-cost,1);
        }
    }
    return dp[n];
}
void flip(){
    for(int i=1;i<=n;i++) s[i]^=1;
}
int solve(){
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+s[i];
    int lb=-1,rb=l+1;
    while(rb-lb>1){
        int mid=(lb+rb)/2;
        if(check(mid).S<=k) rb=mid; else lb=mid;  
    }
    P p=check(rb);
    int res=p.F+1LL*k*rb;
    return n-res;
}
int main()
{
    scanf("%d%d%d",&n,&k,&l);
    scanf("%s",str);
    for(int i=0;i<n;i++) {if(str[i]>='A'&&str[i]<='Z') s[i+1]=1; else s[i+1]=0; }
    int ans=solve(); flip(); ans=min(ans,solve());
    printf("%d\n",ans);
    return 0;
}

