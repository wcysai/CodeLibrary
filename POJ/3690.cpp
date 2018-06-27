#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<assert.h>
#define MAXN 1005
#define MAXT 105
using namespace std;
typedef unsigned long long ull;
int N,M,T,P,Q;
char field[MAXN][MAXN];
char patterns[MAXT][MAXN][MAXN];
ull h[MAXN][MAXN],tmp[MAXN][MAXN];
void compute_h(char a[MAXN][MAXN],int n,int m)
{
	const ull B1=9973;
	const ull B2=100000007;
	ull t1=1;
	for(int j=0;j<Q;j++) t1*=B1;
	for(int i=0;i<n;i++)
	{
		ull e=0;
		for(int j=0;j<Q;j++) e=e*B1+a[i][j];
		for(int j=0;j+Q<=m;j++)
		{
			tmp[i][j]=e;
			if(j+Q<m) e=e*B1-t1*a[i][j]+a[i][j+Q];
		}
	}
	ull t2=1;
	for(int i=0;i<P;i++) t2*=B2;
	for(int j=0;j+Q<=m;j++)
	{
		ull e=0;
		for(int i=0;i<P;i++) e=e*B2+tmp[i][j];
		for(int i=0;i+P<=n;i++)
		{
			h[i][j]=e;
			if(i+P<n) e=e*B2-t2*tmp[i][j]+tmp[i+P][j];
		}
	}
}
void solve()
{
	multiset<ull> unseen;
	for(int k=0;k<T;k++)
	{
		compute_h(patterns[k],P,Q);
		unseen.insert(h[0][0]);
	}
	compute_h(field,N,M);
	for(int i=0;i+P<=N;i++)
		for(int j=0;j+Q<=M;j++)
			unseen.erase(h[i][j]);
	int ans=T-unseen.size();
	printf("%d\n",ans);
}
int main()
{
	int cnt=0;
	while(scanf("%d%d%d%d%d",&N,&M,&T,&P,&Q)==5)
	{
		if(N==0&&M==0&&T==0&&P==0&&Q==0) break;
		for(int i=0;i<N;i++)
			scanf("%s",field[i]);
		for(int i=0;i<T;i++)
		{
			getchar();
			for(int j=0;j<P;j++)
				scanf("%s",patterns[i][j]);
		}
		printf("Case %d: ",++cnt);
		solve();
	}
	return 0;
}