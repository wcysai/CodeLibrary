#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 10005
#define MAXD 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,d;
int dp[MAXN][MAXD][2];
string str;
void add(int &a,int b){a+=b; if(a>=MOD) a-=MOD;}
int solve(int now,int sum,int smaller)
{
    if(now==n) return sum==0?1:0;
    if(dp[now][sum][smaller]!=-1) return dp[now][sum][smaller];
    int limit=smaller?9:str[now]-'0';
    int ans=0;
    for(int i=0;i<=limit;i++) add(ans,solve(now+1,(sum+i)%d,smaller|(i<limit)));
    return dp[now][sum][smaller]=ans;
}
int main()
{
    cin>>str;n=str.size();
    scanf("%d",&d);
    memset(dp,-1,sizeof(dp));
    printf("%d\n",(solve(0,0,0)-1+MOD)%MOD);
    return 0;
}

