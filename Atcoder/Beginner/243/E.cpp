#include<bits/stdc++.h>
#define MAXN 305
#define INF 1000000000000000000LL
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
ll a[MAXN][MAXN],d[MAXN][MAXN];
void floyd_warshall()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=d[i][j]=(i==j?0:INF);
	for(int i=0;i<m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		a[u][v]=a[v][u]=d[u][v]=d[v][u]=w;
	}
	floyd_warshall();
	int need=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(a[i][j]==INF) continue;
			bool f=true;
			for(int k=1;k<=n;k++)
			{
				if(k==i||k==j) continue;
				if(d[i][k]+d[k][j]<=a[i][j]) f=false; 
			}
			if(f) need++;
		}
	printf("%d\n",m-need);
	return 0;
}