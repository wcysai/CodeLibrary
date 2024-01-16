#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 150
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll n,sz,s,ans;
ll dp[15][2][2][MAXM][MAXM];
vector<int> v;
ll solve(int cur,int smaller,int zero,int sum,int mod){
    //printf("cur=%d smaller=%d zero=%d sum=%d mod=%d\n",cur,smaller,zero,sum,mod);
    if(cur==(int)v.size()){
        return ((!zero)&&mod==0&&sum==s)?1:0;
    }
    if(dp[cur][smaller][zero][sum][mod]!=-1) return dp[cur][smaller][zero][sum][mod];
    ll res=0;
    int limit=smaller?9:v[cur];
    //printf("limit=%d\n",limit);
    for(int i=0;i<=limit;i++){
        //printf("i=%d\n",i);
        res+=solve(cur+1,smaller||(i<limit),zero&&(i==0),sum+i,(10*mod+i)%s);
    }
    return dp[cur][smaller][zero][sum][mod]=res;
}
ll get_ans(int sum){
    s=sum;
    memset(dp,-1,sizeof(dp));
    return solve(0,0,1,0,0);
}
int main(){
    scanf("%lld",&n);
    while(n) {v.push_back(n%10); n/=10;}
    reverse(v.begin(),v.end());
    for(int i=1;i<=140;i++) 
        ans+=get_ans(i);
    printf("%lld\n",ans);
    return 0;
}

