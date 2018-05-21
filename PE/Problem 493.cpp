#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
typedef long long ll;
double comb(int n,int k)
{
	double s=1.0;
	for(int i=n-k+1;i<=n;i++)
		s=s*i;
	for(int i=1;i<=k;i++)
		s=s/i;
	printf("%d %d %.10f\n",n,k,s);
	return s;
}
int main()
{
	double ans=0;
	ans=7*(1-comb(60,20)/comb(70,20));
	printf("%.10f\n",ans);
	return 0;
}