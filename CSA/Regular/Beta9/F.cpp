#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 205
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n;
char str[MAXN];
//1: 1
//10: 10
//100: 100
//1000: 91
//10000: 1
//dp[l][r][mod][len%4]
int dp[MAXN][MAXN][MAXN][4];
void add(int &a,int b) {a+=b; if(a>=MOD) a-=MOD;}
void dec(int &a,int b) {a-=b; if(a<0) a+=MOD;}
int pow_mod(int a,int i)
{
    int s=1;
    while(i)
    {
        if(i&1) s=1LL*s*a%101;
        a=1LL*a*a%101;
        i>>=1;
    }
    return s;
}
int solve(int l,int r,int mod,int rem)
{
    //printf("%d %d %d %d\n",l,r,mod,rem);
    if(l>r)
    {
        if(mod==0&&rem==0) return 1;
        return 0;
    }
    if(l==r)
    {
        if(mod==0&&rem==0) return 1;
        if(mod==str[l]-'0'&&rem==1) return 1;
        return 0;
    }
    int &ans=dp[l][r][mod][rem];
    if(ans!=-1) return ans;
    ans=0;
    add(ans,solve(l,r-1,mod,rem));add(ans,solve(l+1,r,mod,rem));
    dec(ans,solve(l+1,r-1,mod,rem));
    if(str[l]==str[r])
    {
        int rrem=0;
        if(rem==1) rrem=1; else if(rem==2) rrem=10; else if(rem==3) rrem=100; else rrem=91;
        rrem=(rrem+1)*(str[l]-'0')%101;
        int to=((mod-rrem+101)*91)%101;
        add(ans,solve(l+1,r-1,to,(rem+2)%4));
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    scanf("%s",str+1);
    memset(dp,-1,sizeof(dp));
    int ans=0;
    for(int i=0;i<4;i++) add(ans,solve(1,n,0,i));
    dec(ans,1);
    printf("%d\n",ans);
    return 0;
}

