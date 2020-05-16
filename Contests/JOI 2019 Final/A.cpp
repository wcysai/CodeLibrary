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
char str[MAXN][MAXN];
int cnto[MAXN][MAXN],cnti[MAXN][MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=m;j>=1;j--)
            cnto[i][j]=cnto[i][j+1]+(str[i][j]=='O');
    for(int i=1;i<=m;i++)
        for(int j=n;j>=1;j--)
            cnti[j][i]=cnti[j+1][i]+(str[j][i]=='I');
    ll ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(str[i][j]=='J') ans+=cnto[i][j]*cnti[i][j];
    printf("%lld\n",ans);
    return 0;
}