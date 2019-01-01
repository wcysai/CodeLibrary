#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
char str[MAXN][MAXN];
int cnt[3],ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
    ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m-2;j++)
        {
            if(str[i][j]=='A'&&str[i][j+1]=='C'&&str[i][j+2]=='M') ans++;
            if(str[i][j]=='M'&&str[i][j+1]=='C'&&str[i][j+2]=='A') ans++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n-2;j++)
        {
            if(str[j][i]=='A'&&str[j+1][i]=='C'&&str[j+2][i]=='M') ans++;
            if(str[j][i]=='M'&&str[j+1][i]=='C'&&str[j+2][i]=='A') ans++;
        }
    }
    for(int i=1;i<=n-1;i++)
    {
        for(int j=1;j<=m-1;j++)
        {
            if(str[i][j]=='A'&&str[i][j+1]=='C'&&str[i+1][j+1]=='M') ans++;
            if(str[i][j]=='M'&&str[i][j+1]=='C'&&str[i+1][j+1]=='A') ans++;
            if(str[i][j]=='A'&&str[i+1][j]=='C'&&str[i+1][j+1]=='M') ans++;
            if(str[i][j]=='M'&&str[i+1][j]=='C'&&str[i+1][j+1]=='A') ans++;
            if(str[i+1][j]=='A'&&str[i][j]=='C'&&str[i][j+1]=='M') ans++;
            if(str[i+1][j]=='M'&&str[i][j]=='C'&&str[i][j+1]=='A') ans++;
            if(str[i+1][j]=='A'&&str[i+1][j+1]=='C'&&str[i][j+1]=='M') ans++;
            if(str[i+1][j]=='M'&&str[i+1][j+1]=='C'&&str[i][j+1]=='A') ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}

