#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,x,y;
string str;
int dp[MAXN][2];
int main()
{
    scanf("%d",&t);
    for(int _=1;_<=t;_++)
    {
        scanf("%d%d",&x,&y);
        cin>>str;
        n=(int)str.size();
        for(int i=0;i<n;i++) dp[i][0]=dp[i][1]=INF;
        dp[0][0]=(str[0]=='J'?INF:0);
        dp[0][1]=(str[0]=='C'?INF:0);
        for(int i=1;i<n;i++)
        {
            if(str[i]=='C'||str[i]=='?') dp[i][0]=min(dp[i][0],min(dp[i-1][0],dp[i-1][1]+y));
            if(str[i]=='J'||str[i]=='?') dp[i][1]=min(dp[i][1],min(dp[i-1][1],dp[i-1][0]+x));
        }
        printf("Case #%d: %d\n",_,min(dp[n-1][0],dp[n-1][1]));
    }
    return 0;
}