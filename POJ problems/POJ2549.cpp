#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#define MAX_N 1000
#define INF 10000000
using namespace std;
struct save
{
	int a;
	int b;
	int c;
};
int n;
int num[MAX_N];
save sum[MAX_N*MAX_N];
int sum1[MAX_N*MAX_N],sum2[MAX_N*MAX_N],sum3[MAX_N*MAX_N];
int cp(int x,int y)
{
	return x>y? x:y;
}
bool operator<(const save &x, const save &y)
{
    return x.a < y.a;
}
int main()
{
	scanf("%d",&n);
	while(n!=0)
	{
	for(int i=0;i<n;i++)
	  scanf("%d",&num[i]);
	for(int i=0;i<n;i++)
	  for(int j=i+1;j<n;j++)
	    if(num[i]>num[j])
	    {
	    	int t=num[j];
	    	num[j]=num[i];
	    	num[i]=t;
		}
	int k=0;
	for(int i=0;i<n;i++)
	  for(int j=i+1;j<n;j++)
	  {
	      	sum[k].a=num[i]+num[j];
	      	sum[k].b=i;
	      	sum[k].c=j;
	      	k++;
		  }
	//		for(int i=0;i<k;i++)
	//	printf("%d %d %d\n",sum[i].a,sum[i].b,sum[i].c);
	sort(sum,sum+k);
	for(int i=0;i<k;i++)
	{
		sum1[i]=sum[i].a;
		sum2[i]=sum[i].b;
		sum3[i]=sum[i].c;
	}
//	for(int i=0;i<k;i++)
//	printf("%d %d %d\n",sum[i].a,sum[i].b,sum[i].c);
	long long maxn=-INF;
	int f=0;
	for(int i=0;i<n;i++)
	  for(int j=i+1;j<n;j++)
	  {
	    int cd=num[j]-num[i];
	    if(upper_bound(sum1,sum1+k,cd)-lower_bound(sum1,sum1+k,cd)>0)
	    {
	    	int p=upper_bound(sum1,sum1+k,cd)-sum1-1;
	    	if(i!=sum2[p]&&i!=sum3[p]&&j!=sum2[p]&&j!=sum3[p])
			{
			   maxn=cp(maxn,num[j]);
			   f=1;
		    }
		}
      }
    if(f) printf("%lld\n",maxn); else printf("no solution\n");
    scanf("%d",&n);
    }
    return 0;
}