#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
int n,k,sum;
int main()
{
	int sum=1,cnt=1;
	for(int i=2;i<=501;i++)
	{
		for(int j=0;j<4;j++)
		{
			cnt+=(i-1)*2;
			sum+=cnt;
		}
	}
	printf("%d\n",sum);
	return 0;
}