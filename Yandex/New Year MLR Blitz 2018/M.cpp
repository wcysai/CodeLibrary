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
int n,k,a[MAXN],b[MAXN];
string x,y;
P dp[20][2][2];
P solve(int now,int less,int greater)
{
    if(now==10) return P(0,0);
    if(dp[now][less][greater]!=P(-1,-1)) return dp[now][less][greater];
    int lb=greater?0:a[now];
    int rb=less?9:b[now];
    int lans=INF,rans=-INF;
    for(int i=lb;i<=rb;i++)
    {
        P to=solve(now+1,less|(i!=rb),greater|(i!=lb));
        lans=min(lans,i+to.F);
        rans=max(rans,i+to.S);
    }
    return dp[now][less][greater]=P(lans,rans);
}
int main()
{
    cin>>x;cin>>y;
    while(x.size()<10) x='0'+x;
    while(y.size()<10) y='0'+y;
    for(int i=0;i<10;i++) a[i]=x[i]-'0';
    for(int i=0;i<10;i++) b[i]=y[i]-'0';
    for(int i=0;i<20;i++) dp[i][0][0]=dp[i][0][1]=dp[i][1][0]=dp[i][1][1]=P(-1,-1);
    P ans=solve(0,0,0);
    printf("%d %d\n",ans.F,ans.S);
    return 0;
}

