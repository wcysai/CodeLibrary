#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define MAXN 105
using namespace std;
char map[MAXN][MAXN];
int dx[9]={-1,0,1,-1,0,1,-1,0,1},dy[9]={-1,-1,-1,0,0,0,1,1,1};
int cnt,n,m;
void dfs(int x,int y)
{
    map[x][y]='.';
    for(int i=0;i<9;i++)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>=0&&ny>=0&&nx<n&&ny<m&&map[nx][ny]=='W')
            dfs(nx,ny);
    }
    return;
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
      scanf("%s",&map[i]);
    cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(map[i][j]=='W')
        {
            dfs(i,j);
            cnt++;
        }
    printf("%d",cnt);
    return 0;
}