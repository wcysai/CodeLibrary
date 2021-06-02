#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,k;
int dp[MAXN][205];
struct node
{
    int r,x,y;
};
node p[MAXN];
bool cmp(node p,node q)
{
    if(p.r!=q.r) return p.r<q.r;
    return p.x+q.y<p.y+q.x;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++) scanf("%d%d%d",&p[i].r,&p[i].x,&p[i].y);
        sort(p,p+n,cmp);
        for(int i=0;i<=n+1;i++)
            for(int j=0;j<=200;j++)
                dp[i][j]=-INF;
        dp[0][0]=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=200;j++)
            {
                if(dp[i][j]==-INF) continue;
                dp[i+1][j]=max(dp[i+1][j],dp[i][j]-min(p[i].x,p[i].y));
                if(j>0) dp[i+1][j-1]=max(dp[i+1][j-1],dp[i][j]-p[i].y+k);
                if(j<100) dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]-p[i].x);
            }
        }
        printf("%d\n",dp[n][0]);
    }
    return 0;
}