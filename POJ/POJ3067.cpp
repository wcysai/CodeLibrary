#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define MAXN 1000
using namespace std;
typedef long long ll;
int bit[MAXN+1];
pair <int,int> a[MAXN*MAXN+20];
int n,m,k;
ll sum(int x)
{
	ll s=0;
	for(int i=x;i>0;i-=i&-i)
	  s+=bit[i];
	return s;
}
void add(int x,int d)
{
	for(int i=x;i<=n;i+=i&-i)
	  bit[i]+=d; 
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int j=1;j<=t;j++)
	{
	scanf("%d%d%d",&m,&n,&k);
	for(int i=0;i<k;i++)
	  scanf("%d%d",&a[i].first,&a[i].second);
	sort(a,a+k);
	memset(bit,0,sizeof(bit));
	ll ans=0;
	for(int i=0;i<k;i++)
	{
		ans+=i-sum(a[i].second);
		add(a[i].second,1);
	}
	printf("Test case %d: %I64d\n",j,ans);
}
	return 0;
}
