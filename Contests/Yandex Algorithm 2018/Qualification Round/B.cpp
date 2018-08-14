#include<bits/stdc++.h>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
queue<int> que;
int n;
int a[MAXN][MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n*2;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	int s,t,r;
	for(int i=0;i<n*2;i++)
		for(int j=i+1;j<n*2;j++)
			if(a[i][0]==a[j][0]) {s=i;t=j;}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2*n;j++)
			if(j!=t&&a[j][0]==a[t][i]) r=j;
		for(int j=0;j<n;j++) printf("%d ",a[r][j]);
	}
	puts("");
	return 0;
}