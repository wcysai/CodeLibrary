#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#define MAX_N 5003
using namespace std;
int n;
int dir[MAX_N];
int f[MAX_N];
int calc(int k)
{
	memset(f,0,sizeof(f));
	int res=0;
	int sum=0;
	for(int i=0;i+k<=n;i++)
	{
		if((dir[i]+sum)%2!=0)
		{
		   res++;
		   f[i]=1;
		}
		sum+=f[i];
		if(i-k+1>=0) sum-=f[i-k+1];
	}
	for(int i=n-k+1;i<n;i++)
	{
     	if((dir[i]+sum)%2!=0) return -1;
     	if(i-k+1>=0) sum-=f[i-k+1];
    }
   return res;
}
void solve()
{
	int K=1,M=n;
	for(int k=1;k<=n;k++)
	{
		int m=calc(k);
		if(m>=0&&M>m)
		{
			M=m;
			K=k;
		}
	}
	printf("%d %d\n",K,M);
}
int main()
{
	scanf("%d",&n);
	char c[2];
	for(int i=0;i<n;i++)
	{
		scanf("%s",c);
		if(c[0]=='B') dir[i]=1; else dir[i]=0;
	}
	  
	solve();
	return 0;
}
