#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int t,n,m;
int deg[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(deg,0,sizeof(deg));
		for(int i=0;i<m;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			deg[x-1]++;
			deg[y-1]++;
		}
		int cnt=0;
		for(int i=0;i<n;i++)
			if(deg[i]%2==0) cnt++;
		printf("%d\n",cnt&1);
	}
	return 0;
}