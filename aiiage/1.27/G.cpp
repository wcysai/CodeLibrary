#include<stdio.h>
#define LL long long
LL ans[250000];
int a[250000], b[250000];
int main(void)
{
	int k, j, p, n, i;
	scanf("%d", &k);
	n = 1;
	for(i=1;i<=k;i++)
		n *= 2;
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);
	for(i=0;i<n;i++)
		scanf("%d", &b[i]);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			while((i&j)!=i)
				j++;
			/*if((i&j)!=i)
			{
				for(p=k-1;p>=0;p--)
				{
					if(i&(1<<p) && (j&(1<<p))==0)
						break;
				}
				j |= (1<<p);
				for(p--;p>=0;p--)
				{
					if(j&(1<<p))
						j -= (1<<p);
				}
			}*/
			ans[i] += a[i]*b[j]+b[i]*a[j];
			if(i==j)
				ans[i] -= a[i]*b[j];
		}
	}
	for(i=0;i<n;i++)
		printf("%lld\n", ans[i]);
	return 0;
}
/*
2
1 2 4 8
2 3 5 8
*/