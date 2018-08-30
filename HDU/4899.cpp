/*************************************************************************
    > File Name: 4899.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-08-31 00:19:23
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,m,s;
int a[20],ans[20];
char str[20];
int dp[1005][1<<15];
int trans[1<<15][5];
int tmp[2][16];
int _mod(int x) {return x>=MOD?x-MOD:x;}
int solve(int state,int ch)
{
    int ans=0;
    memset(tmp,0,sizeof(tmp));
    for(int i=0;i<n;i++) tmp[0][i+1]=tmp[0][i]+((state>>i)&1);
    for(int i=1;i<=n;i++)
    {
        int mx=0;
        if(a[i]==ch) mx=tmp[0][i-1]+1;
        mx=max(max(mx,tmp[0][i]),tmp[1][i-1]);
        tmp[1][i]=mx;
    }
    for(int i=0;i<n;i++) ans+=(1<<i)*(tmp[1][i+1]-tmp[1][i]);
    return ans;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        memset(ans,0,sizeof(ans));
        memset(dp,0,sizeof(dp));
        scanf("%s",str+1);
        scanf("%d",&m);
        n=strlen(str+1);s=1<<n;
        for(int i=1;i<=n;i++)
        {
            if(str[i]=='A') a[i]=1;
            else if(str[i]=='T') a[i]=2;
            else if(str[i]=='C') a[i]=3;
            else a[i]=4;
        }
        for(int state=0;state<s;state++)
            for(int j=1;j<=4;j++)
                trans[state][j]=solve(state,j);
        dp[0][0]=1;
        for(int i=1;i<=m;i++)
            for(int state=0;state<s;state++)
                for(int k=1;k<=4;k++)
                    dp[i][trans[state][k]]=_mod(dp[i][trans[state][k]]+dp[i-1][state]);
        for(int state=0;state<s;state++)
            ans[__builtin_popcount(state)]=_mod(ans[__builtin_popcount(state)]+dp[m][state]);
        for(int i=0;i<=n;i++) printf("%d\n",ans[i]);
    }
    return 0;
}

