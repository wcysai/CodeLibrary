#include<bits/stdc++.h>
#define MAXN 405
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
vector<int> v[3];
string str;
int dp[MAXN][MAXN][3],ndp[MAXN][MAXN][3];
int pre[3][3][MAXN][MAXN];
void upd(int &a,int b) {a=min(a,b);}
int main()
{
    scanf("%d",&n);
    cin>>str;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='R') v[0].push_back(i);
        else if(str[i]=='G') v[1].push_back(i);
        else v[2].push_back(i);
    }
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        {
            if(i==j) continue;
            for(int k=0;k<(int)v[i].size();k++)
            {
                for(int l=0;l<=(int)v[j].size();l++)
                {
                    if(l==0) pre[i][j][k][l]=0;
                    else pre[i][j][k][l]=pre[i][j][k][l-1]+(v[j][l-1]>v[i][k]);
                }
            }
        }
    for(int j=0;j<=n;j++)
        for(int k=0;k<=n;k++)
            for(int l=0;l<3;l++)
                dp[j][k][l]=INF;
    dp[0][0][0]=dp[0][0][1]=dp[0][0][2]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=n;j++)
            for(int k=0;k<=n;k++)
                for(int l=0;l<3;l++)
                    ndp[j][k][l]=INF;
        for(int j=0;j<=i;j++)
            for(int k=0;j+k<=i;k++)
            {
                for(int l=0;l<3;l++)
                {
                    if(dp[j][k][l]==INF) continue;
                    for(int p=0;p<3;p++)
                    {
                        if(p==l) continue;
                        if(p==0&&j==(int)v[0].size()) continue;
                        if(p==1&&k==(int)v[1].size()) continue;
                        if(p==2&&i-j-k==(int)v[2].size()) continue;
                        if(p==0) upd(ndp[j+1][k][0],dp[j][k][l]+pre[0][1][j][k]+pre[0][2][j][i-j-k]);
                        else if(p==1) upd(ndp[j][k+1][1],dp[j][k][l]+pre[1][0][k][j]+pre[1][2][k][i-j-k]);
                        else upd(ndp[j][k][2],dp[j][k][l]+pre[2][0][i-j-k][j]+pre[2][1][i-j-k][k]);
                    }
                }
            }
        swap(dp,ndp);
    }
    int ans=INF;
    for(int i=0;i<3;i++) ans=min(ans,dp[v[0].size()][v[1].size()][i]);
    if(ans==INF) puts("-1"); else printf("%d\n",ans);
    return 0;
}