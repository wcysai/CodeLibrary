#include<stdio.h>
#define LL long long
LL F[10000005] = {0,1};
int Jud(int x)
{
	int i;
	if(x==2)
		return 1;
	for(i=2;i<=x-1;i++)
	{
		if(x%i==0)
			return 0;
	}
	return 1;
}
int main(void)
{
	int T, mod, i;
	T = 1;
	while(T--)
	{
		for(mod=2;mod<=500;mod++)
		{
			/*if(Jud(mod)==0)
				continue;*/
			for(i=2;i<=10000000;i++)
			{
				F[i] = (F[i-1]+F[i-2])%mod;
				if(F[i]%mod==1 && F[i-1]%mod==0)
				{
					printf("%d %d\n", mod, i-1);
					break;
				}
			}
		}
	}
	return 0;
}