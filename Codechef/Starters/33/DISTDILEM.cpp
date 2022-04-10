#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n;
ll s;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		s=0;
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			s+=x;
		}
		int ans=0;
		ll tmp=0;
		for(int i=1;;i++)
		{
			tmp+=i;
			if(tmp>s) break;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}