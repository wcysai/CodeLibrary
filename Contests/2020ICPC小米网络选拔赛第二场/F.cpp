#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,lpos[MAXN];
int dp[MAXN][MAXN];
int sum[MAXN][MAXN];
int st[MAXN][20];
int pre[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void init(int n,int *arr)
{
    pre[1]=0;
    for(int i=2;i<=n+1;i++)
    {
        pre[i]=pre[i-1];
        if ((1<<pre[i]+1)==i) ++pre[i];
    }
    for(int i=n;i>=0;i--)
    {
        st[i][0]=arr[i];
        for(int j=1;(i+(1<<j)-1)<=n;++j)
            st[i][j]=max(st[i][j-1],st[i+(1<<j-1)][j-1]);
    }
}
int query(int l,int r)
{
    if(l>r) return 0;
    int len=r-l+1,k=pre[len];
    return max(st[l][k],st[r-(1<<k)+1][k]);
}
int p6[MAXN];
int main()
{
    p6[0]=1;
    for(int i=1;i<=1000;i++) p6[i]=6LL*p6[i-1]%MOD;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1;i<=n;i++) lpos[i]=0;
        for(int i=0;i<m;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            lpos[r]=max(lpos[r],l);
        }
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
        init(n,lpos);
        dp[0][0]=sum[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int maxpos=query(j,i-1);
                if(maxpos>j) dp[i][j]=0; 
                else 
                {
                    if(maxpos==0) dp[i][j]=2LL*sum[j][j]*p6[i-j-1]%MOD;
                    else dp[i][j]=2LL*(sum[j][j]-sum[j][maxpos-1]+MOD)*p6[i-j-1]%MOD;
                }
                if(maxpos>j);
                else if(maxpos==0) add(dp[i][i],2LL*sum[j][j]*p6[i-j-1]%MOD);
                else add(dp[i][i],2LL*(sum[j][j]-sum[j][maxpos-1]+MOD)*p6[i-j-1]%MOD);
            }
            sum[i][0]=dp[i][0];
            for(int j=1;j<=i;j++) sum[i][j]=sum[i][j-1],add(sum[i][j],dp[i][j]);
        }
        int ans=0;
        for(int i=0;i<=n;i++) 
            for(int j=0;j<=i;j++)
            {
                int maxpos=query(i,n);
                if(maxpos>j) continue;
                add(ans,1LL*dp[i][j]*p6[n-i]%MOD);
            }
        printf("%d\n",ans);
    }
}