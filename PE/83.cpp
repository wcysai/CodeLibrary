#include<bits/stdc++.h>
#define MAXN 105
#define MAXV 6450
#define INF 1000000000
using namespace std;
int mat[MAXN][MAXN];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n=80;
int cost[MAXV][MAXV];
int d[MAXV];
bool used[MAXV];
int V;
void dijkstra(int s)
{
    fill(d,d+V,INF);
    fill(used,used+V,false);
    d[s]=0;
    while(true)
    {
        int v=-1;
        for(int u=0;u<V;u++)
            if(!used[u]&&(v==-1||d[u]<d[v])) v=u;
        if(v==-1) break;
        used[v]=true;
        for(int u=0;u<V;u++)
            d[u]=min(d[u],d[v]+cost[v][u]);
    }
}
int main()
{
	freopen("p083_matrix.txt", "r", stdin);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&mat[i][j]);
	V=6400;
	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			cost[i][j]=INF;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			int id=i*n+j;
			for(int k=0;k<4;k++)
			{
				int nx=i+dx[k],ny=j+dy[k];
				if(nx<0||ny<0||nx==n||ny==n) continue;
				int nid=nx*n+ny;
				cost[id][nid]=mat[nx][ny];
			}
		}
	dijkstra(0);
	printf("%d\n",d[6399]+mat[0][0]);
	fclose(stdin);
	return 0;
}