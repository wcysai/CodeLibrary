#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string str;
int n;
int dp[MAXN][MAXN];
int solve(int l,int r)
{
    if(l>r) return 0;
    if(l==r)
    {
        if(str[l]=='*') return 0; else return 1;
    }
    if(dp[l][r]!=-1) return dp[l][r];
    if(str[l]=='*'&&str[r]=='*') return dp[l][r]=min(solve(l+1,r),solve(l,r-1));
    if(str[l]=='*') return dp[l][r]=min(solve(l+1,r),solve(l,r-1)+2);
    if(str[r]=='*') return dp[l][r]=min(solve(l,r-1),solve(l+1,r)+2);
    if(str[l]!='?'&&str[r]!='?'&&str[l]!=str[r]) return dp[l][r]=INF;
    else return dp[l][r]=solve(l+1,r-1)+2;
}
int main()
{
    cin>>str;
    n=(int)str.size();
    memset(dp,-1,sizeof(dp));
    int ans=solve(0,n-1);
    if(ans>=INF) puts("-1"); else printf("%d\n",ans);
}