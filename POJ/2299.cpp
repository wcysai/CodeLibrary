#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MAXN 500000
using namespace std;
typedef long long ll;
int bit[MAXN+1],a[MAXN],n;
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
 pair<int,int> dum[MAXN];
 int main() 
 {
 	scanf("%d",&n);
 	memset(a,0,sizeof(a));
 	memset(dum,0,sizeof(dum)); 
 	while(n!=0)
 	{
 	for(int i=0;i<n;i++)
 	{
 		scanf("%d",&a[i]);
 		dum[i].first=a[i];
 		dum[i].second=i;
	 }
	 sort(dum,dum+n);
	 for(int i=0;i<n;i++)
	   a[dum[i].second]=i+1;
	memset(bit,0,sizeof(bit));
	 ll sm=0;
	for(int i=0;i<n;i++)
	{
		sm+=i-sum(a[i]);
		add(a[i],1);
	}
	printf("%lld\n",sm);
	scanf("%d",&n);
}
	return 0;
 }