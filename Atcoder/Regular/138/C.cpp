#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,a[MAXN];
P p[MAXN];
int tmp[MAXN];
ll s;
int main()
{
	scanf("%d",&n);
	s=0;
	for(int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i]); 
		p[i]=P(a[i],i);
	}
	ll ans=0;
	sort(p+1,p+n+1);
	memset(tmp,-1,sizeof(tmp));
	for(int i=n/2+1;i<=n;i++) ans+=p[i].F;
	for(int i=1;i<=n/2;i++) tmp[p[i].S]=1;
	P mini=P(0,0);
	for(int i=1;i<=n-1;i++) 
	{
		tmp[i]+=tmp[i-1];
		mini=min(mini,P(tmp[i],i));
	}
	printf("%d %lld\n",mini.S,ans);
	return 0;
}