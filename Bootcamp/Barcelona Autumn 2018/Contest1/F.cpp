/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-26 21:57:53
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000001
#define MOD 1000000007
#define F first
#define S second
#define pow10 roundgod
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll N,n,a[MAXN];
ll dp[MAXN][MAXN];//dp[i][j]:number[1..i] changed j times 
ll cnt[MAXN];
ll nxt[MAXN][12][12]; //nxt[i][j][k]:number[i..i+j-1] revised k times
ll pow10[12];
ll cur[12];
bool rev[12];
char str[MAXN];
int main()
{
    pow10[0]=1;
    for(ll i=1;i<=10;i++) pow10[i]=10*pow10[i-1];
    scanf("%lld",&N);
    scanf("%s",str+1);
    n=strlen(str+1);
    for(ll i=1;i<=n;i++)
        if(str[i]=='+') cnt[i]=cnt[i-1]+1; else cnt[i]=cnt[i-1];
    for(ll i=1;i<=n;i++)
    {
        for(ll j=0;j<=10;j++)
            for(ll k=0;k<=10;k++)
                nxt[i][j][k]=INF;
        for(ll j=1;j<=min(10LL,n-i+1);j++)
        {
            if(j==1) 
            {
                if(str[i]=='+') {nxt[i][j][1]=0; continue;}
                else {nxt[i][j][0]=str[i]-'0'; nxt[i][j][1]=0; continue;}
            }
            ll c=0,now=0;
            memset(rev,false,sizeof(rev));
            for(ll k=i;k<=i+j-1;k++)
            {
                if(str[k]=='+'||(k==i&&str[k]=='0')) 
                {
                    if(k!=i) {cur[k-i]=0; c++; rev[k-i]=true;}
                    else {cur[k-i]=1; c++; rev[k-i]=true; now+=pow10[j-1];}
                }
                else {cur[k-i]=str[k]-'0'; now+=pow10[i+j-1-k]*(str[k]-'0'); rev[k-i]=false;}
            }
            nxt[i][j][c]=now;
            for(ll k=0;k<j;k++)
            {
                if(c==j) break;
                if(k==0&&!rev[k]&&cur[k]>1)
                {
                    c++;
                    now-=(cur[k]-1)*pow10[j-1-k];
                    nxt[i][j][c]=now;
                    continue;
                }
                else if(k==0) continue;
                else if(!rev[k]&&cur[k]!=0)
                {
                    c++;
                    now-=cur[k]*pow10[j-1-k];
                    nxt[i][j][c]=now;
                }
            }
            for(ll k=c+1;k<=j;k++) nxt[i][j][k]=nxt[i][j][k-1];
        }
    }
    for(ll i=0;i<=n;i++)
        for(ll j=0;j<=n;j++)
            dp[i][j]=INF;
    for(ll i=1;i<=n;i++)
    {
        for(ll j=0;j<=i;j++)
        {
            for(ll k=1;k<=min(10LL,i);k++)
            {
                for(ll l=0;l<=min(j,k);l++)
                {
                    ll need;
                    if(i==k) need=l; else need=l+(str[i-k]=='+'?0:1);
                    if(need>j) continue;
                    if(i==k) dp[i][j]=min(dp[i][j],nxt[1][k][l]);
                    else dp[i][j]=min(dp[i][j],dp[i-k-1][j-need]+nxt[i-k+1][k][l]);
                }
            }
            //printf("%lld %lld %lld\n",i,j,dp[i][j]);
        }
    }
    for(ll i=0;i<=n;i++) if(dp[n][i]<=N) {printf("%lld\n",i); return 0;}
    puts("-1");
    return 0;
}

