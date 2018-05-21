#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int pow_mod(int a,int x)
{
	int s=1;
	for(int i=1;i<=x;i++)
		s*=a;
	return s;
}
int main()
{
	int sum=0;
	for(int i=2;i<=9;i++)
	{
		if(i%2==0) sum+=20*pow_mod(30,i/2-1);
		else if(i%4==3) sum+=100*pow_mod(500,i/4);
	}
	printf("%d\n",sum);
	return 0;
}