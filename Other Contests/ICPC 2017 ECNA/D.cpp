#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
int n,k;
int a[MAXN],st[MAXN];
char str[10];
int main()
{
	scanf("%d%d",&n,&k);
	int t=0,now=0;
	for(int i=0;i<k;i++)
	{
		scanf("%s",str);
		if(str[0]=='u')
		{
			scanf("%s",str);
			int num=atoi(str);
			while(num)
			{
				t--;
				now=(now+n-st[t])%n;
				num--;
			}
		}
		else
		{
			int num=atoi(str);
			num=(num%n+n)%n;
			now=(now+num)%n;
			st[t++]=num;
		}
	}
	printf("%d\n",now);
	return 0;
}