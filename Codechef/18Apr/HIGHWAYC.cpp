#include<bits/stdc++.h>
#define eps 1e-6
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,s,y;
int v[MAXN],d[MAXN],p[MAXN],c[MAXN];
double l[MAXN],r[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&s,&y);
		double tt=(double)y/s;
		for(int i=0;i<n;i++)
			scanf("%d",&v[i]);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&d[i]);
			if(d[i]==0) d[i]=-1;
		}
		for(int i=0;i<n;i++)
			scanf("%d",&p[i]);
		for(int i=0;i<n;i++)
			scanf("%d",&c[i]);
		for(int i=0;i<n;i++)
		{
			l[i]=min((double)INF,(double)p[i]/(-v[i]*d[i]));
			r[i]=max(0.0,(double)(p[i]-d[i]*c[i])/(-v[i]*d[i]));
			//printf("%f %f\n",l[i],r[i]);
		}
		double now=0;
		for(int i=0;i<n;i++)
		{
			if(r[i]<l[i]) {now+=tt; continue;}
			if(now+tt-l[i]<-eps||r[i]-now<-eps) {now+=tt; continue;}
			now=r[i]+tt;
		}
		printf("%.10f\n",now);
	}
	return 0;
}