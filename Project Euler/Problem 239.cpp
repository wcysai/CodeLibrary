#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
double fact(int x)
{
	double s=1.0;
	for(int i=1;i<=x;i++)
		s=s*i;
	return s;
}
double comb(int n,int k)
{
	return fact(n)/fact(k)/fact(n-k);
}
int main()
{
	double ans=0;
	double f=1.0;
	for(int i=0;i<=22;i++)
	{
		ans=ans+f*comb(22,i)*fact(97-i);
		f=-f;
	}
	ans=ans*comb(25,3);
	ans=ans/fact(100);
	printf("%.20f\n",ans);
	return 0;
}