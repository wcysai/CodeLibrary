#include<stdio.h>
#define LL long long
#define mod 1500000001
int main(void)
{
	LL ans;
	int i, j;
	freopen("in.txt", "w", stdout);
	for(i=0;i<=1100;i++)
	{
		ans = 1;
		for(j=i*1000000+1;j<=(i+1)*1000000;j++)
			ans = ans*j%mod;
		printf(",%lld", ans);
	}
	printf("}");
	return 0;
}