#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int dp[MAXN][(1<<16)];
void upd(int &a,int b) {a=min(a,b);}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<=n;i++)
        for(int j=0;j<(1<<16);j++)
            dp[i][j]=INF;
    dp[0][0]=0;
    for(int i=0;i<n;i++)
    {
        for(int mask=0;mask<(1<<k);mask++)
        {
            if(dp[i][mask]==INF) continue;
            //choose
            if(!(mask&(1<<(a[i+1]-1))))
            {
                int bmask=(~((1<<(a[i+1]-1))-1))&mask;
                int num=__builtin_popcount(bmask);
                //add inversions inside permutation
                upd(dp[i+1][mask|(1<<(a[i+1]-1))],dp[i][mask]+num);
            }
            //not choose
            int num=min(__builtin_popcount(mask),k-__builtin_popcount(mask));
            upd(dp[i+1][mask],dp[i][mask]+num);
        }
    }
    printf("%d\n",dp[n][(1<<k)-1]);
    return 0;
}