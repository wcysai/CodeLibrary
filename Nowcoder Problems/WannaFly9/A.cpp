#include<bits/stdc++.h>
#define MAXN 1000005
using namespace std;
int num[MAXN];
int n;
int main()
{
	scanf("%d",&n);
	memset(num,0,sizeof(num));
	int s=0;
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		num[x]++;
		s=max(x,s);
	}
	int ans=0;
	for(int i=1;i<=s-1;i++)
	{
		if(!num[i]) continue;
		for(int j=2*i;j<=s;j+=i)
			if(num[j]) {ans+=num[i]; break;}
	}
	printf("%d\n",ans);
	return 0;
}