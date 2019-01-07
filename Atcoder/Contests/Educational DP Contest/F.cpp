#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 3005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
char s[MAXN+1],t[MAXN+1];
int dp[MAXN][MAXN],op[MAXN][MAXN];
int main()
{
    scanf("%s",s+1);scanf("%s",t+1);
    n=strlen(s+1);m=strlen(t+1);
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(s[i]==t[j]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    int x=n,y=m;
    deque<char> ans;
    while(x>=1&&y>=1)
    {
        if(s[x]==t[y]) {ans.push_front(s[x]); x--; y--;}
        else if(dp[x-1][y]>dp[x][y-1]) x--;
        else y--;
    }
    for(auto ch:ans) printf("%c",ch);
    return 0;
}

