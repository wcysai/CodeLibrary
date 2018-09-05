#include<bits/stdc++.h>
#define MAXN 100005
#define F first
#define S second
using namespace std;
typedef pair<int,int> P;
int n,k;
P a[MAXN];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++) 
		scanf("%d%d",&a[i].F,&a[i].S);
	sort(a,a+n);
	int ans=k,cnt=0;
	for(int i=0;i<n;i++)
	{
		cnt=cnt+a[i].S;
		if(a[i].F>k) ans=min(ans,a[i].F-cnt); else ans=min(ans,k-cnt);
	}
	printf("%d\n",ans);
	return 0;
}