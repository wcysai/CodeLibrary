#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 4000005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
int mini[MAXN];
int main()
{
	scanf("%d%d",&n,&k);
	int ans=INF;
	for(int i=1;i<=n;i++) 
		scanf("%d",&a[i]);
	for(int i=k-1;i>=1;i--) a[i]=min(a[i],a[i+1]);
	for(int i=k+1;i<=n;i++)
	{
		if(a[i]<=a[1]) continue;
		int l=1,r=k+1;
		while(r-l>1)
		{
			int mid=(l+r)/2;
			if(a[mid]<a[i]) l=mid; else r=mid;
		}
		ans=min(ans,i-l);
	} 
	if(ans==INF) puts("-1"); else printf("%d\n",ans);
	return 0;
}