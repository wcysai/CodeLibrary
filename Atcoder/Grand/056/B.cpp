#include<bits/stdc++.h>
#define MAXN 305
#define MAXM 50005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef bitset<301> bs;
typedef long long ll;
typedef pair<int,int> P;
int n,m,l[MAXM],r[MAXM];
bs has[MAXN][MAXN];
int dp[MAXN][MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
bs construct(int l,int r)
{
    bs tmp;
    for(int i=l;i<=r;i++) tmp.set(i);
    return tmp;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) 
    {
        scanf("%d%d",&l[i],&r[i]);
        has[l[i]][r[i]]|=construct(l[i],r[i]);
    }

    for(int len=2;len<=n;len++)
    {
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            has[i][j]|=has[i][j-1];
            has[i][j]|=has[i+1][j];
        }
    }
    puts("here");
    for(int i=1;i<=n+1;i++) dp[i][i-1]=1;
    for(int len=1;len<=n;len++)
    {
        for(int i=1;i+len-1<=n;i++)
        {
            int j=i+len-1;
            if(!has[i][j].any()) dp[i][j]=1;
            else 
            {
                dp[i][j]=0;
                for(int k=has[i][j]._Find_first();k!=has[i][j].size();k=has[i][j]._Find_next(k))
                {
                    printf("i=%d j=%d k=%d\n",i,j,k);
                    add(dp[i][j],1LL*dp[i][k-1]*dp[k+1][j]%MOD);
                }
            }
            printf("i=%d j=%d dp=%d\n",i,j,dp[i][j]);
        }
    }
    printf("%d\n",dp[1][n]);
    return 0;
}