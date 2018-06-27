#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int n;
int a[MAXN];
int main()
{
	scanf("%d",&n);
	a[0]=1;
	a[n-1]=n;
	int cnt=0;
	for(int i=1;i<n-1;i+=2)
	{
		cnt+=2;
		a[i]=cnt+1;
		a[i+1]=cnt;
	}
	if(n%2==0) a[n-1]=n;
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;

}