#include<bits/stdc++.h>
#define MAXN 1005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
ll n,q;
ll grid1[MAXN][MAXN],grid2[MAXN][MAXN];
ll sum[MAXN][MAXN];
int main()
{
	scanf("%lld%lld",&n,&q);
	memset(grid1,0,sizeof(grid1));
	memset(grid2,0,sizeof(grid2));
	for(ll i=0;i<q;i++)
	{
		ll r,c,l,s;
		scanf("%lld%lld%lld%lld",&r,&c,&l,&s);
		r--;c--;
		grid1[r][c]+=s;
		grid1[min(r+l,n)][c]-=s;
		grid2[r][min(c+1,n)]-=s;
		grid2[min(r+l,n)][min(c+l+1,n)]+=s;
	}
	memset(sum,0,sizeof(sum));
	for(ll i=1;i<n;i++)
		for(ll j=0;j<n;j++)
			grid1[i][j]+=grid1[i-1][j];
	for(ll i=n-2;i>=0;i--)
		for(ll j=1;i+j<n;j++)
			grid2[i+j][j]+=grid2[i+j-1][j-1];
	for(ll j=1;j<n;j++)
		for(ll i=1;i+j<n;i++)
			grid2[i][i+j]+=grid2[i-1][i+j-1];
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			grid1[i][j]+=grid2[i][j];
	for(ll i=0;i<n;i++)
		for(ll j=0;j<n;j++)
			sum[i][j]=j==0?grid1[i][j]:sum[i][j-1]+grid1[i][j];
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n;j++)
			printf("%lld ",sum[i][j]);
		printf("\n");
	}
	printf("\n");
	return 0;
}