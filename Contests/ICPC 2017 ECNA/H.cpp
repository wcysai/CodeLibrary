#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
int n,m;
char mp[MAXN][MAXN];
bool used[MAXN][MAXN];
int dx[8]={1,1,1,-1,-1,-1,0,0};
int dy[8]={0,1,-1,0,1,-1,1,-1};
void dfs(int x,int y)
{
	used[x][y]=true;
	for(int i=0;i<8;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(nx>=0&&nx<n&&ny>=0&&ny<m&&mp[nx][ny]=='#'&&!used[nx][ny]) dfs(nx,ny);
	}
	return;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%s",mp[i]);
	memset(used,false,sizeof(used));
	int cnt=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(mp[i][j]=='#'&&!used[i][j])
			{
				cnt++;
				dfs(i,j);
			}
	printf("%d\n",cnt);
	return 0;
}