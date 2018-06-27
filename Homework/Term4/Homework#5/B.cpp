#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
int n,k;
double a[MAXN],b[MAXN],c[MAXN];
bool C(double x)
{
	for(int i=1;i<=n;i++)
		c[i]=100*a[i]-x*b[i];
	sort(c+1,c+n+1);
	double ans=0;
	for(int i=n;i>k;i--)
		ans+=c[i];
	return ans>=0;
}
int main()
{
	while(scanf("%d%d",&n,&k)==2)
	{
		if(n==0&&k==0) break;
		for(int i=1;i<=n;i++)
			scanf("%lf",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%lf",&b[i]);
		double lb=0,rb=100;
		for(int i=0;i<100;i++)
		{
			double mid=(lb+rb)/2;
			if(C(mid)) lb=mid; else rb=mid;
		}
		printf("%d\n",(int)(lb+0.5));
	}
	return 0;
}