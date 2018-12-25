/*************************************************************************
    > File Name: F.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-12-23 12:23:22
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m,ans;
int relate[MAXN][2];
//0: withitself
//1: with a[i-1]
//2: with a[i-2]
int dp[MAXN][2];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%MOD;
        a=1LL*a*a%MOD;
        i>>=1;
    }
    return s;
}
//1..n: 0
//n+1..2n 1
map<P,int> mp;
int main()
{
    scanf("%d%d",&n,&m);
    int cnt=(1LL*n*(n-1)/2)%(MOD-1);
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        mp[P(x,y)]=z;
    }
    memset(relate,-1,sizeof(relate));
    for(auto it:mp)
    {
        int x=it.F.F,y=it.F.S,z=it.S;
        if(x>y) 
        {
            if(mp.find(P(y,x))==mp.end()) cnt--;
            continue;
        }
        if(x==y)
        {
            if(relate[x][0]!=-1&&relate[x][0]!=z) {puts("0"); return 0;}
            relate[x][0]=z;
        }
        else 
        {
            cnt--;if(cnt<0) cnt+=MOD;
            if(mp.find(P(y,x))==mp.end()) continue;
            int s=(z+mp[P(y,x)])%2;
            if(y-x>2&&s==1) {puts("0"); return 0;}
            if(y-x==1)
            {
                if(relate[y][1]!=-1&&relate[y][1]!=s) {puts("0"); return 0;}
                relate[y][1]=s;
            }
            else if(y-x==2)
            {
                if(relate[x+1][0]!=-1&&relate[x+1][0]!=s) {puts("0"); return 0;}
                relate[x+1][0]=s;
            }
        }
    }
    memset(dp,0,sizeof(dp));
    if(relate[1][0]!=-1) 
    {
        int x=relate[1][0];
        dp[1][1-x]=0;dp[1][x]=1;
    }
    else {dp[1][0]=dp[1][1]=1;}
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=1;j++)
        {
            if(!dp[i][j]) continue;
            for(int k=0;k<=1;k++)
            {
                bool f=true;
                if(relate[i+1][0]!=-1&&relate[i+1][0]!=k) f=false;
                if(relate[i+1][1]!=-1&&relate[i+1][1]!=(j+k)%2) f=false;
                if(f) add(dp[i+1][k],dp[i][j]);
            }
        }
    }
    add(ans,dp[n][0]);add(ans,dp[n][1]);
    ans=1LL*ans*pow_mod(2,cnt)%MOD;
    printf("%d\n",ans);
    return 0;
}

