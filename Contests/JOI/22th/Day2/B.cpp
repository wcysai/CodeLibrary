#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300005
#define MAXM 20
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,mask[MAXN],cnt[20];
int dp[(1<<20)][21],ndp[(1<<20)][21];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;scanf("%d",&x);
            if(x) {cnt[j]++; mask[i]+=(1<<j);}
        }
        dp[mask[i]][0]++;
    }
    for(int i=0;i<m;i++){
        memset(ndp,0,sizeof(ndp));
        for(int mask=0;mask<(1<<m);mask++){
            for(int c=0;c<=i+1;c++){
                if(mask&(1<<i)){
                    if(c) ndp[mask][c]+=dp[mask^(1<<i)][c-1];
                    ndp[mask][c]+=dp[mask][c];
                }
                else{
                    ndp[mask][c]=dp[mask][c];
                    ndp[mask][c]+=dp[mask^(1<<i)][c];
                }
            }
        }
        swap(dp,ndp);
    }
    for(int i=0;i<n;i++){
        int c=0,nmask=0;
        for(int j=0;j<m;j++){
            int num=cnt[j]-((mask[i]>>j)&1);
            if(num>n/2) c++;
            else if(num==n/2) nmask|=(1<<j);
        }
        int ans=0;
        for(int j=0;j<=m;j++){
            int z=dp[nmask][j];
            if(__builtin_popcount((~mask[i])&nmask)==j) z--;
            if(z) ans=max(ans,c+j);
        }
        printf("%d\n",ans);
    }
    return 0;
}

