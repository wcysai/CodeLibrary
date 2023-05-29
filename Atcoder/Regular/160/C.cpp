#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200055
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN],cnt[MAXN],maxi[MAXN];
vector<int> dp[MAXN],sum[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int solve(int now,int addon){
    if(dp[now][addon]!=-1) return dp[now][addon];
    if(now>200000&&addon==0) return 1;
    int num=cnt[now]+addon,res=0;
    for(int i=0;i<=num/2;i++) add(res,solve(now+1,i));
    return dp[now][addon]=res;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {scanf("%d",&a[i]); cnt[a[i]]++;}
    for(int i=1;i<=200032;i++){
        maxi[i]=(maxi[i-1]+cnt[i-1])/2;
        dp[i].resize(maxi[i]+1); sum[i].resize(maxi[i]+1);
    }
    for(int i=200032;i>=1;i--){
        for(int addon=0;addon<=maxi[i];addon++){
            if(i>200000&&addon==0) dp[i][addon]=1;
            else dp[i][addon]=sum[i+1][(cnt[i]+addon)/2];
        }
        sum[i][0]=dp[i][0];
        for(int addon=1;addon<=maxi[i];addon++) {sum[i][addon]=sum[i][addon-1]; add(sum[i][addon],dp[i][addon]);}
    }
    printf("%d\n",dp[1][0]);
    return 0;
}

