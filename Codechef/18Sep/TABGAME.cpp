/*************************************************************************
    > File Name: TABGAME.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-12 09:14:03
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define left lhynb
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,q;
string xx,yy;
int left[45][MAXN],up[45][MAXN];
int find(int x,int y)
{
    return !(x&y);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        cin>>xx;cin>>yy;
        m=(int)xx.size(),n=(int)yy.size();
        int need=max(n,m);need=min(40,need);
        for(int i=1;i<=m;i++) up[1][i]=xx[i-1]-'0';
        for(int i=1;i<=n;i++) left[1][i]=yy[i-1]-'0';
        for(int i=2;i<=need;i++)
        {
            up[i][0]=left[i][0]=find(up[i-1][1],left[i-1][1]);
            for(int j=1;j<=m+1-i;j++)
                up[i][j]=find(up[i-1][j+1],up[i][j-1]);
            for(int j=1;j<=n+1-i;j++)
                left[i][j]=find(left[i-1][j+1],left[i][j-1]);
        } 
        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);x++;y++;
            if(x<=need||y<=need)
            {
                if(x<=y) printf("%d",up[x][y-x]);
                else printf("%d",left[y][x-y]);
            }
            else
            {
                if(x<=y) printf("%d",up[need][y-x]);
                else printf("%d",left[need][x-y]);
            }
        }
    }
    return 0;
}

