#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,N,l[MAXN];
map<int,int> mp;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&N);
		mp.clear();
		for(int i=1;i<=N;i++) 
		{
			int x;
			scanf("%d",&x);
			mp[x]++;
		}
		int ans=0,cnt=0;
		for(auto p:mp)
		{
			if(p.S&1) ans++;
			cnt+=(p.S+1)/2;
		}
		if(cnt&1) ans+=2;
		printf("%d\n",ans); 
	}
	return 0;
}