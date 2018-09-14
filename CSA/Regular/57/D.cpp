/*************************************************************************
    > File Name: D.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-14 21:41:38
 ************************************************************************/

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
char str[MAXN];
int dp[MAXN][MAXN][26];
int _mod(int x,int y) 
{
    int s=x+y;
    return s>=MOD?s-MOD:s;
}
int solve(int l,int r,int ch)
{
    if(l>r) return 0;
    if(l==r) return (str[l]==ch+'a')?1:0;
    if(dp[l][r][ch]!=-1) return dp[l][r][ch];
    int res;
    if(str[l]=='a'+ch&&str[r]=='a'+ch)
    {
        res=2;
        for(int i=0;i<26;i++) res=_mod(res,solve(l+1,r-1,i));
    }
    else res=_mod(solve(l+1,r,ch),solve(l,r-1,ch))-solve(l+1,r-1,ch);
    if(res<0) res+=MOD;
    return dp[l][r][ch]=res;
}
int main()
{
    scanf("%s",str+1);
    n=strlen(str+1);
    memset(dp,-1,sizeof(dp));
    int ans=0;
    for(int i=0;i<26;i++) ans=_mod(ans,solve(1,n,i));
    printf("%d\n",ans);
    return 0;
}

