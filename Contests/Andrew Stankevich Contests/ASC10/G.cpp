#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int l,m;
int a[MAXN];
int w[MAXN][MAXN];
int dp[MAXN][MAXN],opt[MAXN][MAXN];
string str;
int main()
{
    freopen("ssh.in","r",stdin);
    freopen("ssh.out","w",stdout);
    scanf("%d%d",&l,&m);
    for(int i=1;i<=l-1;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&w[i][j]);
    for(int i=0;i<=l;i++)
        for(int j=1;j<=m;j++)
            dp[i][j]=INF;
    for(int j=1;j<=m;j++) dp[0][j]=0;
    for(int i=0;i<l-1;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(dp[i][j]==INF) continue;
            for(int k=1;k<=m;k++)
            {
                if(dp[i+1][k]>dp[i][j]+abs(w[j][k]-a[i+1]))
                {
                    dp[i+1][k]=dp[i][j]+abs(w[j][k]-a[i+1]);
                    opt[i+1][k]=j;
                }
            }
        }
    }
    int ans=INF,ch=-1;
    for(int i=1;i<=m;i++)
    {
        if(dp[l-1][i]<ans)
        {
            ans=dp[l-1][i];
            ch=i;
        }
    }
    int now=l-1; str="";
    str+=(char)ch+'a'-1;
    while(now>0)
    {
        ch=opt[now][ch];
        now--;
        str=(char)(ch+'a'-1)+str;
    }
    cout<<str<<endl;
    return 0;
}
