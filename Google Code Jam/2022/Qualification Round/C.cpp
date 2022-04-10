#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,s[MAXN];
bool check(int x)
{
	for(int i=1;i<=x;i++) if(s[n-x+i]<i) return false;
	return true;
}
int main()
{
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&s[i]);
		sort(s+1,s+n+1);
		int l=1,r=n+1;
		while(r-l>1)
		{
			int mid=(l+r)/2;
			if(check(mid)) l=mid; else r=mid;
		}
		printf("Case #%d: %d\n",t,l);
	}
	return 0;
}