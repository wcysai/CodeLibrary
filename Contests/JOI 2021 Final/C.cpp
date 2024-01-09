#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 5005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,h[MAXN],pos[MAXN];
int cnt[MAXN][MAXN];//cnt[i][j]: how many [1,j] in [1,i]
int dp[MAXN];//dp[i]: minimum number of inversions after first i elements
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {scanf("%d",&h[i]); pos[h[i]]=i;}
    for(int i=1;i<=n;i++) cnt[i][h[i]]++;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cnt[i][j]+=cnt[i][j-1]+cnt[i-1][j]-cnt[i-1][j-1];
    dp[0]=0;
    for(int i=1;i<=n;i++) dp[i]=INF;
    for(int i=0;i<n;i++){
        int num=0;
        for(int j=1;i+j<=n;j++){//put [i+j,i+j-1,...,i+1]
            int p=pos[i+j];
            num+=p-1-cnt[p-1][i];//how many [1,i] is after p
            num-=(j-1)-(cnt[p-1][i+j-1]-cnt[p-1][i]);//how many [i+1,i+j-1] is after p
            dp[i+j]=min(dp[i+j],dp[i]+num);
        }
    }
    printf("%d\n",dp[n]);
    return 0;
}

