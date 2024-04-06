#include<bits/stdc++.h>
#define MAXN 100005
#define MAXM 55
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,a[MAXN];
double dp[(1<<18)][MAXM];
int mask[MAXM];
ll eq[(1<<18)][MAXM];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int k;
        scanf("%d",&k);
        for(int j=0;j<k;j++) {
            int x;
            scanf("%d",&x);
            mask[i]|=(1<<x);
        }
    }
    for(int i=0;i<m;i++)
        for(int j=i+1;j<m;j++)
            if(mask[i]==mask[j]) {puts("not possible"); return 0;}
    for(int mm=(1<<n)-1;mm>=0;mm--)
        for(int i=0;i<m;i++)
            for(int j=0;j<m;j++) if((mask[j]&mm)==(mask[i]&mm)) eq[mm][i]|=(1LL<<j);
    for(int mm=((1<<n)-1);mm>=0;mm--){
        for(int i=0;i<m;i++){
            dp[mm][i]=1e9;
            int sz=__builtin_popcountll(eq[mm][i]);
            //printf("mask=%d i=%d sz=%d\n",mm,i,sz);
            if(sz<=1) {dp[mm][i]=0; continue;}
            for(int nxt=0;nxt<n;nxt++){
                if(mm&(1<<nxt)) continue;
                int num=__builtin_popcountll(eq[mm|(1<<nxt)][i]);
                double res=1.0;
                if(num) res+=1.0*num/sz*dp[mm|(1<<nxt)][i];
                if(sz-num) res+=1.0*(sz-num)/sz*dp[mm|(1<<nxt)][__builtin_ctzll(eq[mm][i]^eq[mm|(1<<nxt)][i])];
                dp[mm][i]=min(dp[mm][i],res);
            }     
        }
    }
    printf("%.10f\n",dp[0][0]);
    return 0;
}

