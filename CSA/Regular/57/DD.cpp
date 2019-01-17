#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
int pre[MAXN][26],suf[MAXN][26];
int dp[MAXN][MAXN];
char str[MAXN];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int solve(int l,int r)
{
    if(l>r) return 1;
    if(l==r) return 2;
    if(dp[l][r]!=-1) return dp[l][r];
    int ans=1;
    for(int i=0;i<26;i++)
    {
        if(suf[l][i]==pre[r][i]) add(ans,1);
        if(suf[l][i]<pre[r][i]) add(ans,1+solve(suf[l][i]+1,pre[r][i]-1));
    }
    //printf("%d %d %d\n",l,r,ans);
    return dp[l][r]=ans;
}
int main()
{
    scanf("%s",str+1);
    n=strlen(str+1);
    //printf("%d\n",n);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<26;j++) pre[i][j]=pre[i-1][j];
        pre[i][str[i]-'a']=i;
    }
    for(int i=0;i<26;i++) suf[n+1][i]=n+1;
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<26;j++) suf[i][j]=suf[i+1][j];
        suf[i][str[i]-'a']=i;
    }
    memset(dp,-1,sizeof(dp));
    int ans=solve(1,n);
    add(ans,MOD-1);
    printf("%d\n",ans);
    return 0;
}

