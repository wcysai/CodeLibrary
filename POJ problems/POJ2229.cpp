#include<cstdio>
int main()
{
	long long  a[1000001];
	int n,i;
	scanf("%d",&n);
	a[1]=1;
	for(i=2;i<=n;i++)
	{
		if (i%2==1) a[i]=a[i-1]; 
		else a[i]=(a[i-1]+a[i/2])%1000000000;
	}
		printf("%d",a[n]);
	return 0;
	}