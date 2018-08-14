#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int t,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int num,num2;
		printf("1 1\n");
		fflush(stdout);
		scanf("%d",&num);
		int l=1,r=n+1,res;
		while(r-l>1)
		{
			int mid=(l+r)/2;
			printf("1 %d\n",mid);
			fflush(stdout);
			scanf("%d",&res);
			if(res>num) {num2=res,r=mid;} else l=mid;
		}
		int len=l;
		if(len==n)
		{
			printf("2 %d\n",num);
			fflush(stdout);
			continue;
		}
		l=r,r=n+1;
		while(r-l>1)
		{
			int mid=(l+r)/2;
			printf("1 %d\n",mid);
			fflush(stdout);
			scanf("%d",&res);
			if(res>num2) r=mid; else l=mid;
		}
		int len2=l-len;
		if(len2<len)
		{
			printf("2 %d\n",num2);
			fflush(stdout);
			continue;
		}
		else if(len2>len)
		{
			printf("2 %d\n",num);
			fflush(stdout);
			continue;
		}
		l=1,r=n/len+1;
		int a,b;
		while(r-l>1)
		{
			int mid=(l+r)/2;
			printf("1 %d\n",mid*len);
			fflush(stdout);
			scanf("%d",&a);
			printf("1 %d\n",mid*len+1);
			fflush(stdout);
			scanf("%d",&b);
			if(a!=b) {l=mid; num=b;} else r=mid;
		}
		printf("2 %d\n",num);
		fflush(stdout);
	}
	return 0;
}