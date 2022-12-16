#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,m;
char str[2][MAXN];
bool vis[2][MAXN];
int go(int x,int y)
{
    vis[x][y]=true; 
    if(!vis[x^1][y]&&str[x^1][y]=='B') {return go(x^1,y)+1;}
    if(y!=m&&!vis[x][y+1]&&str[x][y+1]=='B') {return go(x,y+1)+1;}
    return 1;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&m);
        int cnt=0;
        for(int i=0;i<2;i++) 
        {
            scanf("%s",str[i]+1);
            for(int j=1;j<=m;j++) if(str[i][j]=='B') cnt++;
        }
        bool f=false;
        memset(vis,false,sizeof(vis));
        if(str[0][1]=='B'&&go(0,1)==cnt) f=true;
        memset(vis,false,sizeof(vis));
        if(str[1][1]=='B'&&go(1,1)==cnt) f=true;
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}

