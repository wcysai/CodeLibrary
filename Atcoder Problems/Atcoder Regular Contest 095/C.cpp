#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
P a[MAXN];
int ans[MAXN];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i].F);
		a[i].S=i;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		if(i<=n/2) ans[a[i].S]=a[n/2+1].F; else ans[a[i].S]=a[n/2].F;
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
	return 0;
}