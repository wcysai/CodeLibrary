#include<bits/stdc++.h>
#define MAXN 65
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,m;
string s,t;
int dp[MAXN][MAXN],rdp[MAXN][MAXN];
int main()
{
    scanf("%d",&T);
    for(int _=1;_<=T;_++)
    {
        cin>>s; cin>>t;
        n=(int)s.size(); m=(int)t.size();
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                dp[i][j]=INF;
        dp[0][0]=0;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
            {
                if(i==0&&j==0) continue;
                if(i) dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
                if(j) dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
                if(i&&j) dp[i][j]=min(dp[i][j],dp[i-1][j-1]+(s[i-1]!=t[j-1]));
            }
        reverse(s.begin(),s.end()); reverse(t.begin(),t.end());
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                rdp[i][j]=INF;
        rdp[0][0]=0;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
            {
                if(i==0&&j==0) continue;
                if(i) rdp[i][j]=min(rdp[i][j],rdp[i-1][j]+1);
                if(j) rdp[i][j]=min(rdp[i][j],rdp[i][j-1]+1);
                if(i&&j) rdp[i][j]=min(rdp[i][j],rdp[i-1][j-1]+(s[i-1]!=t[j-1]));
            }
        int ans=dp[n][m];
        string str="";
        reverse(s.begin(),s.end()); reverse(t.begin(),t.end());
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
            {
                if(dp[i][j]==ans/2&&rdp[n-i][m-j]==(ans+1)/2)
                {
                    str=s.substr(0,i)+t.substr(j);
                }
            }
        printf("Case #%d: ",_);
        cout<<str<<endl;
    }
    return 0;
}