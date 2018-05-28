#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<assert.h>
#include<queue>
#include<stack>
#include<deque>
#define MAXN 75
#define MAXM 105
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
int query,n,chuochuo[MAXN];
vector<int> G[MAXN];
int main()
{
	scanf("%d",&query);
	while(query--)
	{
		scanf("%d",&n);
		n*=3;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&chuochuo[i]);
			G[i].clear();
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(i/3!=j/3&&chuochuo[i]+chuochuo[j]!=0) G[i].push_back(j);
		printf("%d %d\n",n,n/3);
		for(int i=0;i<n;i++)
		{
			printf("%d",i);
			for(int j=0;j<G[i].size();j++)
				printf(" %d",G[i][j]);
			if(i!=n-1) puts("");
		}
		if(query) printf("\n\n");
	}
	return 0;
}