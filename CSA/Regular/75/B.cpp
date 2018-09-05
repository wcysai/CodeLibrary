/*************************************************************************
    > File Name: 75B.cpp
    > Author: Roundgod
    > Mail: wcysai@foxmail.com 
    > Created Time: 2018-09-04 12:18:04
 ************************************************************************/

#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int H,W;
int curx,cury,res;
char mp[MAXN][MAXN];
int ans[MAXN][MAXN];
bool vis[MAXN][MAXN];
int main()
{
    scanf("%d%d",&H,&W);
    for(int i=1;i<=H;i++) scanf("%s",mp[i]+1);
    queue<P> que;
    for(int i=1;i<=H;i++)
    {
        que.push(P(i,0));
        que.push(P(i,W+1));
    }
    for(int i=1;i<=W;i++)
    {
        que.push(P(0,i));
        que.push(P(H+1,i));
    }
    int ans=-2*(H+W);
    while(que.size())
    {
        P p=que.front();que.pop();
        ans++;
        int x=p.F,y=p.S;
        if(x+1>=1&&x+1<=H&&y>=1&&y<=W&&!vis[x+1][y]&&mp[x+1][y]=='U') {que.push(P(x+1,y)); vis[x+1][y]=true;}
        if(x-1>=1&&x-1<=H&&y>=1&&y<=W&&!vis[x-1][y]&&mp[x-1][y]=='D') {que.push(P(x-1,y)); vis[x-1][y]=true;}
        if(x>=1&&x<=H&&y+1>=1&&y+1<=W&&!vis[x][y+1]&&mp[x][y+1]=='L') {que.push(P(x,y+1)); vis[x][y+1]=true;}
        if(x>=1&&x<=H&&y-1>=1&&y-1<=W&&!vis[x][y-1]&&mp[x][y-1]=='R') {que.push(P(x,y-1)); vis[x][y-1]=true;}
    }
    printf("%d\n",ans);
    return 0;
}

