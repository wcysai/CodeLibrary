#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int tot,n,m;
char s[MAXN],t[MAXN];
bool dp[MAXN][4][7];
void upd(bool &a) {a=true;}
int main()
{
    scanf("%d",&tot);
    while(tot--)
    {
        scanf("%s",s+1);
        scanf("%s",t+1);
        n=strlen(s+1); m=strlen(t+1);
        if(n-m>3||m-n>3) 
        {
            puts("What you entered is too different from the real password.");
            continue;
        }
        for(int i=0;i<=n;i++)
            for(int j=0;j<=3;j++)
                for(int k=0;k<7;k++)
                    dp[i][j][k]=false;
        dp[0][0][3]=true;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=3;j++)
            {
                for(int k=0;k<7;k++)
                {
                    if(!dp[i][j][k]) continue;
                    if(j<3&&k) upd(dp[i+1][j+1][k-1]);
                    if(j<3&&k!=6) upd(dp[i][j+1][k+1]);
                    int len=i+(k-3);
                    if(len<m)
                    {
                        if(s[i+1]==t[len+1]) upd(dp[i+1][j][k]);
                        else if(j<3) upd(dp[i+1][j+1][k]);
                    } 
                }
            }
        }
        int shift=m-n+3;
        if(dp[n][0][shift]) puts("You're logged in!");
        else if(dp[n][1][shift]) puts("You almost got it. You're wrong in just one spot.");
        else if(dp[n][2][shift]) puts("You almost got it, but you're wrong in two spots.");
        else if(dp[n][3][shift]) puts("You're wrong in three spots.");
        else puts("What you entered is too different from the real password.");
    }
    return 0;
}