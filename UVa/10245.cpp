#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
using namespace std;
typedef pair<double,double> P;
int N;
P A[MAXN];
bool compare_y(P a,P b)
{
	return a.second<b.second;
}
double closest_pair(P *a,int n)
{
	if(n<=1) return INF;
	int m=n/2;
	double x=a[m].first;
	double d=min(closest_pair(a,m),closest_pair(a+m,n-m));
	inplace_merge(a,a+m,a+n,compare_y);
	vector<P> b;
	for(int i=0;i<n;i++)
	{
		if(fabs(a[i].first-x)>=d) continue;
		for(int j=0;j<b.size();j++)
		{
			double dx=a[i].first-b[b.size()-j-1].first;
			double dy=a[i].second-b[b.size()-j-1].second;
			if(dy>=d) break;
			d=min(d,sqrt(dx*dx+dy*dy));
		}
		b.push_back(a[i]);
	}
	return d;
}
double solve()
{
	sort(A,A+N);
	return closest_pair(A,N);
}
int main()
{
	while(scanf("%d",&N)==1)
	{
		if(N==0) break;
		for(int i=0;i<N;i++)
			scanf("%lf%lf",&A[i].first,&A[i].second);
		double ans=solve();
		if(ans>=10000) printf("INFINITY\n");
		else printf("%.4f\n",ans);
	}
	return 0;
}