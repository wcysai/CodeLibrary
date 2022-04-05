#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N;
int calc(int x)
{
	int s=0;
	while(x)
	{
		s^=(x&1);
		x/=10;
	}
	return s;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		int s=calc(N);
		int x=N+1;
		while(calc(x)==s) x++;
		printf("%d\n",x);
	}
	return 0;
}