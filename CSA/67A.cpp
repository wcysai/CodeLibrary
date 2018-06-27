#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int a[MAXN],num[MAXN];
int n,ans;
int main()
{
	scanf("%d",&n);
	memset(num,0,sizeof(num));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		num[(i-a[i]+n)%n]++;
	}
	ans=0;
	for(int i=0;i<n;i++)
		ans=max(ans,num[i]);
	printf("%d\n",ans);
	return 0;
}