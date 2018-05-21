#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<algorithm>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define PI 3.14159265
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
double S,lb,rb;
double find_volume(double r)
{
	double R=S/PI/r-r;
	return 1.0/3*sqrt(R*R-r*r)*PI*r*r;
}
double find_height(double r)
{
	double R=S/PI/r-r;
	return sqrt(R*R-r*r);
}
int main()
{
	while(scanf("%lf",&S)==1)
	{
		double lb=0,rb=sqrt(S/PI/2);
		for(int i=0;i<100;i++)
		{
			double llb=lb+(rb-lb)/3,rrb=lb+(rb-lb)*2/3;
			//printf("%f %f %f %f\n",llb,rrb,find_volume(llb),find_volume(rrb));
			if(find_volume(llb)>find_volume(rrb)) rb=rrb; else lb=llb;
		}
		printf("%.2f\n%.2f\n%.2f\n",find_volume(lb),find_height(lb),lb);
	}
	return 0;
}