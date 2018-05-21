#include<bits/stdc++.h>
#define MAXN 10005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
double r,ans;
double _pow(double r,int x)
{
	double res=1;
	for(int i=0;i<x;i++)
		res=res*r;
	return res;
}
int main()
{
	double lb=1.0000005,rb=1.13;
	for(int i=0;i<200;i++)
	{
		double mid=(lb+rb)/2;
		ans=900*(_pow(mid,5000)-1)/(mid-1)-3*5000*_pow(mid,5000)/(mid-1)+3*(_pow(mid,5000)-1)/(mid-1)/(mid-1);
		printf("%.12f %.12lf\n",mid,ans);
		if(ans<-600000000000) rb=mid; else lb=mid;
	}
	printf("%.12lf\n",lb);
	return 0;
}