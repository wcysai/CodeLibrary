#include<bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int money[]={1,2,5,10,20,50,100,200};
int dp[201][10];
int find_ans(int x,int num)
{
	if(dp[x][num]!=-1) return dp[x][num];
	if(x==0) return dp[x][num]=1;
	if(num==8) return 0;
	int sum=0;
	for(int i=0;money[num]*i<=x;i++)
		sum+=find_ans(x-money[num]*i,num+1);
	return dp[x][num]=sum;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	printf("%d\n",find_ans(200,0));
	return 0;
}