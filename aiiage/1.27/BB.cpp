#include<stdio.h>
#include<string.h>
#define LL long long
char str[100005];
int jug[105], yes[105], pri[105] = {1,998244353, 1000000007, 210715, 33153, 9125, 384, 3586, 873, 135, 39486, 295, 2835, 126, 346, 8223912, 23873223, 12153, 23564,1024,16,2};
int main(void)
{
	int T, i, ok, j, len;
	for(i=22;i<=50;i++)
		pri[i] = pri[i-1]*2;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s", str+1);
		len = strlen(str+1);
		if(str[1]=='-' || str[1]=='0')
		{
			printf("No\n");
			continue;
		}
		memset(jug, 0, sizeof(jug));
		for(i=1;i<=len;i++)
		{
			for(j=1;j<=50;j++)
				jug[j] = (jug[j]*10+str[i]-'0')%pri[j];
		}
		for(i=1;i<=50;i++)
			yes[i] = 1;
		ok = 0;
		for(i=1;i<=400000;i++)
		{
			for(j=1;j<=50;j++)
				yes[j] = yes[j]*2%pri[j];
			for(j=1;j<=50;j++)
			{
				if(yes[j]!=jug[j])
					break;
			}
			printf("%d\n", j);1
			if(j==51)
				ok = 1;
		}
		if(ok || str[1]=='1' && len==1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}