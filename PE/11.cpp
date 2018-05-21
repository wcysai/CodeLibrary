#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int grid[20][20];
int main()
{
	for(int i=0;i<20;i++)
		for(int j=0;j<20;j++)
			scanf("%d",&grid[i][j]);
	int ans=0;
	for(int i=0;i<=16;i++)
		for(int j=0;j<20;j++)
			ans=max(ans,grid[i][j]*grid[i+1][j]*grid[i+2][j]*grid[i+3][j]);
	for(int i=0;i<20;i++)
		for(int j=0;j<=16;j++)
			ans=max(ans,grid[i][j]*grid[i][j+1]*grid[i][j+2]*grid[i][j+3]);
	for(int i=0;i<=16;i++)
		for(int j=0;j<=16;j++)
			ans=max(ans,grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3]);
	for(int i=0;i<=16;i++)
		for(int j=3;j<20;j++)
			ans=max(ans,grid[i][j]*grid[i+1][j-1]*grid[i+2][j-2]*grid[i+3][j-3]);
	printf("%d\n",ans);
	return 0;
}