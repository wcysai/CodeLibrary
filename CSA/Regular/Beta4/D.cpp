#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,t;
int dp[MAXN][MAXN][2];
P a[MAXN],b[MAXN];
P st[MAXN];
void relax(int &a,int b) {a=max(a,b);}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].F,&a[i].S);
    for(int i=1;i<=m;i++) scanf("%d%d",&b[i].F,&b[i].S);
    sort(a+1,a+n+1);sort(b+1,b+m+1);
    for(int i=1;i<=m;i++)
    {
        while(t>0&&st[t].S<=b[i].S) t--;
        st[++t]=b[i];
    }
    m=t;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i||j) dp[i][j][0]=dp[i][j][1]=INF;
            if(i>0) 
            {
                dp[i][j][0]=min(dp[i][j][0],max(dp[i-1][j][0],a[i].F)+a[i].S);
                dp[i][j][0]=min(dp[i][j][0],max(dp[i-1][j][1],a[i].F)+a[i].S);
            }
            if(j>0)
            {
                dp[i][j][1]=min(dp[i][j][1],max(dp[i][j-1][0],st[j].F)+st[j].S);
                dp[i][j][1]=min(dp[i][j][1],max(dp[i][j-1][1],st[j].F+st[j].S));
            }
        }
    }
    printf("%d\n",min(dp[n][m][0],dp[n][m][1]));
    return 0;
}

