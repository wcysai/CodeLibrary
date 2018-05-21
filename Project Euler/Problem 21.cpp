#include<bits/stdc++.h>
#define MAXN 10005
using namespace std;
int find_sum(int x)
{
	int s=0;
	for(int i=1;i*i<=x;i++)
	{
		if(x%i==0)
		{
			if(i*i==x) s+=i;
			else s+=i+x/i;
		}
	}
	return s-x;
}
int main()
{
	int sum=0;
	for(int i=1;i<10000;i++)
	{
		if(find_sum(i)!=i&&find_sum(find_sum(i))==i) 
		{
			printf("%d\n",i);
			sum+=i;
		}
	}
	printf("%d\n",sum);
	return 0;
}