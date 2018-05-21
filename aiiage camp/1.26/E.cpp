#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
vector<int> G[200005];
queue<int> q;
int out[200005];
int main(void)
{
	int T, n, i, x, y, now, flag;
	scanf("%d", &T);
	while(T--)
	{
		memset(out, 0, sizeof(out));
		scanf("%d", &n);
		for(i=0;i<=n;i++)
			G[i].clear();
		for(i=1;i<=n-1;i++)
		{
			scanf("%d", &x);
			G[x].push_back(i);
			out[x]++;
		}
		q.push(0);
		flag = now = 0;
		while(q.empty()==0)
		{
			x = q.front();
			q.pop();
			now++;
			if(G[x].size()==2)
			{
				if(out[G[x][0]]<out[G[x][1]])
					swap(G[x][0], G[x][1]);
			}
			for(i=0;i<G[x].size();i++)
			{
				y = G[x][i];
				if(flag)
					printf(" ");
				printf("%d", now-1);
				flag = 1;
				q.push(y);
			}
		}
		puts("");
	}
	return 0;
}
/*
3
3
2 0
7
0 1 6 0 1 4
8
0 0 1 1 2 2 2
*/