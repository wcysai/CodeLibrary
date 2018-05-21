#include<bits/stdc++.h>
#define MAXN 1000005
using namespace std;
int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}
int main()
{
	double ans=(double)3/7;
	int t=-1;
	for(int i=10;i<=1000000;i++)
	{
		for(int j=(int)i*3/7-5;;j++)
		{
			if(j*7>3*i) break;
			if(gcd(i,j)!=1) continue;
			if((double)3/7-(double)j/i<ans)
			{
				ans=(double)3/7-(double)j/i;
				t=j;
			}
		}
	}
	printf("%.10f %d\n",ans,t);
	return 0;
}