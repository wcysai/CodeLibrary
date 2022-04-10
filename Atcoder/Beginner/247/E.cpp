#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,x,y,a[MAXN];
int last[4];
int main()
{
	scanf("%d%d%d",&n,&x,&y);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]);
		if(a[i]>x||a[i]<y) a[i]=-1;
	} 
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==x) last[0]=i;
		if(a[i]==y) last[1]=i;
		if(a[i]==-1) last[2]=i;
		ans+=max(0,min(last[0],last[1])-last[2]);
	}
	printf("%lld\n",ans);
	return 0;
}