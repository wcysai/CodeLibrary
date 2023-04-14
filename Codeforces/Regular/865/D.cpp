#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 65
#define INF 1000000000
#define MOD 998244353
#define INV 499122177
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,m;
ll n;
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int ways[MAXN][2],sum[MAXN][2];
void solve(int now,int carry){
    if(ways[now][carry]!=-1) return;
    if(now==0){
        int z=carry*2+((n>>now)&1);
        if(z==0) {ways[now][carry]=1; sum[now][carry]=0;}
        else if(z==1) {ways[now][carry]=1; sum[now][carry]=1;}
        else if(z==2) {ways[now][carry]=1; sum[now][carry]=0;}
        else {ways[now][carry]=0; sum[now][carry]=0;}
    //printf("now=%d carry=%d ways=%d sum=%d\n",now,carry,ways[now][carry],sum[now][carry]);
        return;
    }
    int z=carry*2+((n>>now)&1);
    if(z==0){
        solve(now-1,0); 
        ways[now][carry]=ways[now-1][0]; sum[now][carry]=sum[now-1][0];
    }
    else if(z==1){
        solve(now-1,0); solve(now-1,1);
        ways[now][carry]=ways[now-1][0]; add(ways[now][carry],ways[now-1][1]);
        sum[now][carry]=sum[now-1][0]; add(sum[now][carry],sum[now-1][1]);
        add(sum[now][carry],1LL*ways[now-1][0]*((1LL<<now)%MOD)%MOD);
    }
    else if(z==2){
    //    printf("nnow=%d carry=%d\n",now,carry);
        solve(now-1,0); solve(now-1,1);
        ways[now][carry]=ways[now-1][0]; add(ways[now][carry],ways[now-1][1]);
        sum[now][carry]=sum[now-1][0]; add(sum[now][carry],sum[now-1][1]);
        add(sum[now][carry],1LL*ways[now-1][1]*((1LL<<now)%MOD)%MOD);
    }
    else if(z==3){
        solve(now-1,1); 
        ways[now][carry]=ways[now-1][1]; sum[now][carry]=sum[now-1][1];
    }
    //printf("now=%d carry=%d z=%d ways=%d sum=%d\n",now,carry,z,ways[now][carry],sum[now][carry]);
}
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%lld%d",&n,&m);
        if(m==1) printf("%lld\n",n%MOD);
        else if(m>=3) printf("%lld\n",1LL*(((n&1)+n)%MOD)*((n/2+1)%MOD)%MOD*INV%MOD);
        else{
            memset(ways,-1,sizeof(ways));
            memset(sum,-1,sizeof(sum));
            solve(61,0); printf("%d\n",sum[61][0]);
        }
    }
    return 0;
}

