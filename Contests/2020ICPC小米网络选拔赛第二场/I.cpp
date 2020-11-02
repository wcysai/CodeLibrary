#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string s,t;
int n,m;
int dp[MAXN][MAXN];
int main()
{
    while(cin>>s)
    {
        cin>>t;
        n=(int)s.size();
        m=(int)t.size();
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if(s[i-1]==t[j-1]) dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
            }
        int ans=0;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
            {
                ans=max(ans,2*dp[i][j]+m-j);
                if(j!=m&&i!=n&&s[i]<t[j]) ans=max(ans,2*dp[i][j]+m-j+n-i);
            }
        printf("%d\n",ans);
    }
}