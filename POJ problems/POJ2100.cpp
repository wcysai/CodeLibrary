#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
long long n;
int main()
{
	scanf("%lld",&n);
	int mem[200][2];
	int cnt=0;
	long long s;
	long long rb=floor(sqrt(n));
	long long lb=rb-1;
	s=rb*rb;
	while((lb>=0)&&(s<n))
	{
	    s+=lb*lb;
	    lb--;
	}
	while(lb>=0)
	{
		if (s==n) 
		{
		   mem[cnt][0]=rb-lb;
		   mem[cnt][1]=lb+1;
		   cnt++;
	    }
		s-=rb*rb;
		rb--;
	    while((lb>=0)&&(s<n))
	    {
	    	s+=lb*lb;
	    	lb--;
		}
	}
	printf("%d\n",cnt);
	for(int i=cnt-1;i>=0;i--)
	{
	  printf("%d ",mem[i][0]);
	  for(int j=mem[i][1];j<=mem[i][0]+mem[i][1]-1;j++)
	    printf("%d ",j);
	  printf("\n");
   }
	return 0;
}