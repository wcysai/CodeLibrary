#include<stdio.h>
#include<algorithm>
using namespace std;
int n, a[100005], id[100005];
typedef struct Res
{
	int id, val;
	bool operator < (const Res &b) const
	{
		if(val<b.val)
			return 1;
		return 0;
	}
}Res;
Res s[100005];
int Jud(int x)
{
	int i, sum = 1;
	for(i=2;i<=n;i++)
	{
		if(a[i]<=x && a[i-1]!=a[i]-1 || a[i]>x && a[i-1]<=x)
			sum++;
	}
	return sum;
}
int main(void)
{
	int T, j, i, l, r, k, m, cnt, x, qaq, flag;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &k);
		for(i=1;i<=n;i++)
		{
			scanf("%d", &a[i]);
			id[a[i]] = i;
		}
		if(k==1)
		{
			printf("%d", a[1]);
			for(i=2;i<=n;i++)
				printf(" %d", a[i]);
			printf("\n");
			continue;
		}
		else if(k==2)
		{
			printf("1");
			for(i=id[1]+1;i<=n;i++)
				printf(" %d", a[i]);
			for(i=1;i<=id[1]-1;i++)
				printf(" %d", a[i]);
			printf("\n");
			continue;
		}
		l = 1, r = n;
		while(l<r)
		{
			m = (l+r+1)/2;
			if(Jud(m)<=k)
				l = m;
			else
				r = m-1;
		}
		cnt = 0;
		for(i=1;i<=n;i++)
		{
			if(a[i]>r && a[i-1]<=r || i==1 && a[i]>r)
				s[++cnt].val = a[i], s[cnt].id = i;
		}
		printf("1");
		for(i=2;i<=r;i++)
			printf(" %d", i);
		if(Jud(r)==k)
		{
			sort(s+1, s+cnt+1);
			for(i=1;i<=cnt;i++)
			{
				for(j=s[i].id;a[j]>r&&j<=n;j++)
					printf(" %d", a[j]);
			}
			printf("\n");
		}
		else
		{
			qaq = -199999;
			for(i=r+1;i<=n;i++)
			{
				x = id[i];
				if(x!=1 && a[x-1]>=i)
				{
					s[++cnt].val = i;
					s[cnt].id = x;
					qaq = i;
					break;
				}
				if(x!=n && a[x+1]>=i+2 && a[id[i+1]-1]<=r)
				{
					s[++cnt].val = a[x+1];
					s[cnt].id = x+1;
					qaq = a[x+1];
					break;
				}
			}
			sort(s+1, s+cnt+1);
			for(i=1;i<=cnt;i++)
			{
				printf(" %d", a[s[i].id]);
				for(j=s[i].id+1;a[j]>r&&j<=n&&a[j]!=qaq;j++)
					printf(" %d", a[j]);
			}
			printf("\n");
		}
	}
	return 0;
}
/*
16
6 4
6 1 3 4 2 5
*/