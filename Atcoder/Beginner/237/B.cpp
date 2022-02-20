#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,m;
vector<int> v[MAXN];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) v[i].resize(n);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&v[j][i]);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			printf("%d ",v[i][j]);
		puts("");
	}
	return 0;
}