#include<cstdio>
#include<cmath>
#include<iostream>
#include<ctime>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#define MAXN 505
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<double,double> P;
double x,y,ans,temp;
P a[MAXN];
int n;
double dis(double x,double y,P p)
{
	return sqrt((p.F-x)*(p.F-x)+(p.S-y)*(p.S-y));
}
double sum(double x,double y)
{
	double s=0;
	for(int i=0;i<n;i++)
		s+=dis(x,y,a[i]);
	return s;
}
int main()
{
	srand(time(NULL));
	scanf("%d",&n);
	x=0;y=0;temp=100000;
	for(int i=0;i<n;i++)
	{
		scanf("%lf%lf",&a[i].F,&a[i].S); 
		x+=a[i].F;y+=a[i].S;
	}
	x/=n;y/=n;
	ans=sum(x,y);
	while(temp>0.02)
	{
		double nx=0,ny=0;
		for(int i=0;i<n;i++)
		{
			nx+=(a[i].F-x)/dis(x,y,a[i]);
			ny+=(a[i].S-y)/dis(x,y,a[i]);
		}
		double res=sum(x+nx*temp,y+ny*temp);
		if(res<ans) {ans=res; x+=temp*nx; y+=temp*ny;}
		else if(log((res-ans)/temp)<(rand()%10000)/10000.0) {ans=res; x+=nx*temp; y+=ny*temp;}
		temp*=0.9;
	}
	printf("%.0f\n",ans);
	return 0;
}