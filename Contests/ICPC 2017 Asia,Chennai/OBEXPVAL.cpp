#include<bits/stdc++.h>
#define MAXN 100005
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
int t,n,E;
P a[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&E);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i].F);
			a[i].S=i;
			a[i].F-=E;
		}
		sort(a,a+n);
		if(a[0].F>0||a[n-1].F<0)
		{
			printf("-1\n");
			continue;
		}
		if(a[0].F==0&&a[n-1].F==0)
		{
			for(int i=0;i<n;i++)
				if(i==0) printf("%10f",1.0); else printf("%10f",0.0);
			printf("\n");
			continue;
		}
		double p1=(double)a[n-1].F/(a[n-1].F-a[0].F),p2=(double)(-a[0].F)/(a[n-1].F-a[0].F);
		for(int i=0;i<n;i++)
		{
			if(i==a[0].S) printf("%.10f ",p1);
			else if(i==a[n-1].S) printf("%.10f ",p2);
			else printf("%.10f ",0.0);
		}
		printf("\n");
	}
	return 0;
}