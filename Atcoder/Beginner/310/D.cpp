#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 15
#define MAXM 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,t,m;
int dp[MAXN][(1<<10)];
bool valid[(1<<10)];
int a[MAXM],b[MAXM];
int main()
{
    scanf("%d%d%d",&n,&t,&m);
    for(int i=1;i<=m;i++) {scanf("%d%d",&a[i],&b[i]); a[i]--; b[i]--;}
    for(int mask=0;mask<(1<<n);mask++){
        valid[mask]=true;
        for(int j=1;j<=m;j++) if((mask&(1<<a[j]))&&(mask&(1<<b[j]))) valid[mask]=false;
    }
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=1;i<=t;i++){
        for(int mask=1;mask<(1<<n);mask++){
            int x=0;
            while(!(mask&(1<<x))) x++;
            for(int submask=1;submask<(1<<n);submask++){
                if(!(submask&(1<<x))) continue;
                if((mask&submask)!=submask) continue;
                if(!valid[submask]) continue;
                dp[i][mask]+=dp[i-1][mask^submask];
            }
        }
    }
    printf("%d\n",dp[t][(1<<n)-1]);
    return 0;
}

