/*************************************************************************
    > File Name: 629.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-06-17 20:30:24
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 300
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
ll t,n,k,a[MAXN];
ll sg[MAXN][MAXN];
bool used[MAXN];
ll dp[MAXN][MAXN];
int main()
{
    ll n=200;
    for(ll i=1;i<=n;i++) sg[2][i]=(i&1?0:1);
    sg[3][1]=0;
    for(ll i=2;i<=n;i++)
    {
        memset(used,false,sizeof(used));
        for(ll j=1;j<i;j++)
        {
            for(ll k=0;j+k<i;k++)
            {
                ll x=i-j-k;
                if(k==0) used[sg[3][j]^sg[3][x]]=true;
                else used[sg[3][j]^sg[3][k]^sg[3][x]]=true;
            }
        }
        for(ll j=0;j<=n;j++)
            if(!used[j]) {sg[3][i]=j; break;}
        //printf("%lld %lld\n",i,sg[3][i]);
    }
    for(ll i=4;i<=n;i++)
        for(ll j=1;j<=n;j++)
            sg[i][j]=j-1;
    ll ans=0,sum;
    for(ll k=2;k<=4;k++)
    {
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(ll i=1;i<=n;i++)
            for(ll j=0;j<=200-i;j++)
                for(ll w=0;w<256;w++)
                    (dp[j+i][w^sg[k][i]]+=dp[j][w])%=MOD;
        sum=0;
        for(ll i=1;i<256;i++)
            (sum+=dp[n][i])%=MOD;
        ans=(ans+sum)%MOD;
        printf("%lld %lld\n",k,sum);
    }
    (ans+=(1LL*sum)*(n-4))%=MOD;
    printf("%lld\n",ans);
    return 0;
}

