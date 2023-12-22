#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 10001
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k;
ll a[MAXN],s[MAXN];
bool dp[MAXN][MAXN];
bool okl[MAXN],okr[MAXN];
ll lb[MAXN],rb[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
        for(int i=1;i<=n;i++) {lb[i]=rb[i]=0; okl[i]=okr[i]=false;}
        for(int l=1;l<=n;l++)
            for(int r=l;r<=n;r++)
                dp[l][r]=false;
        dp[1][n]=true;
        for(int len=n;len>=1;len--){
            for(int l=1;l+len-1<=n;l++){
                int r=l+len-1;
                ll ss=s[l-1]^s[r];
                if(okl[l]) dp[l][r]=true;
                if(okr[r]) dp[l][r]=true;
                if(ss&lb[l]) dp[l][r]=true; 
                if(ss&rb[r]) dp[l][r]=true;
                if(dp[l][r]){
                    if(!ss) {okl[l]=okr[r]=true; continue;}
                    int num=63-__builtin_clzll(ss);
                    lb[l]|=(1LL<<num); rb[r]|=(1LL<<num);
                }
            }
        }
        for(int i=1;i<=n;i++) if(dp[i][i]) printf("1"); else printf("0");
        printf("\n");
    }
    return 0;
}

