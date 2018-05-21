#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int t,n,k,a[MAXN];
bool cut[MAXN];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		memset(cut,false,sizeof(cut));
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		if(k==1)
		{
			for(int i=0;i<n;i++)
				printf("%d",&a[i]);
			printf("\n");
			continue;
		}
	}
}