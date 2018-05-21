#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
double dpow(double x,int k)
{
	double s=1.0;
	for(int i=1;i<=k;i++)
		s*=x;
	return s;
}
int main()
{
	double ans=0;
	for(int i=2;i<=15;i++)
	{
		double p=(double)2.0/(i+1);
		double s=1.0;
		for(int j=1;j<=i;j++)
			s*=pow(p*j,j);
		ans+=floor(s);
		if(i==10) printf("%.10f\n",floor(s));
	}
	printf("%.10f\n",ans);
	return 0;
}