#include<stdio.h>
#define LL long long
#define mod 1500000001
int main(void)
{
	int n, m, i;
	while(scanf("%d%d", &n, &m)!=EOF)
	{
		LL ans = 1;
		for(i=0;i<=m;i++)
			ans = ans*(n^i)%mod;
		printf("%lld\n", ans);
	}
	return 0;
}