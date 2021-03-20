#include<bits/stdc++.h>
#define MAXN 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
char str[MAXN][MAXN];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%s",str[i]);
    bool f=true;
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(str[i][j]=='#') cnt++;
    if(cnt!=n+m-1) f=false;
    if(str[0][0]!='#') f=false;
    int x=0,y=0;
    while(true)
    {
        if(x!=n-1&&str[x+1][y]=='#') x++;
        else if(y!=m-1&&str[x][y+1]=='#') y++;
        else break;
    }
    if(x!=n-1||y!=m-1) f=false;
    if(f) puts("Possible"); else puts("Impossible");
    return 0;
}