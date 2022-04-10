#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 2005
#define INF 1000000000
#define MOD 998244353
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		if(N==-1) exit(0);
		vector<int> v;
		ll sum=0;
		for(int i=0;i<=29;i++)
		{
			printf("%d ",(1<<i));
			sum+=(1<<i);
		}
		int now=(1<<29)+1;
		for(int i=30;i<=99;i++)
		{
			printf("%d%c",now,i==99?'\n':' ');
			sum+=now;
			v.push_back(now);
			now++;
		}
		fflush(stdout);
		for(int i=1;i<=N;i++)
		{
			int x; scanf("%d",&x);
			sum+=x;
			v.push_back(x);
		}
		assert(sum%2==0);
		sort(v.begin(),v.end());
		sum/=2;
		while(sum>1000000000)
		{
			sum-=v.back();
			printf("%d%c",v.back(),sum==0?'\n':' ');
			v.pop_back();
		}
		for(int i=0;i<=29;i++)
		{
			if(sum&(1<<i))
			{
				sum-=(1<<i);
				printf("%d%c",(1<<i),sum==0?'\n':' ');
			}
		}
		fflush(stdout);
	}
	return 0;
}