#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,r,b,dp[MAXN][MAXN];
bool C(int x)
{
	memset(dp,0,sizeof(dp));
	for(int i=0;i<x;i++)
	{
		int restr=r-(i+1);
		int restb=b-(i+1);
		dp[1][]
	}
	return false;
}
int main()
{
	scanf("%d",&t);
	int kase=0;
	while(t--)
	{
		kase++;
		scanf("%d%d",&r,&b);
		int lb=1,rb=200;
		while(rb-lb>1)
		{
			int mid=(lb+rb)/2;
			if(C(mid)) lb=mid; else rb=mid;
		}
		printf("Case #%d: %d\n",kase,lb-1);
	}
	return 0;
}